/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Error.hpp"
#include "IComponent.hpp"
#include "AShell.hpp"
#include <iostream>
#include <algorithm>
#include <unordered_map>

nts::Circuit *nts::Circuit::getInstance()
{
    static Circuit *instance = nullptr;

    if (instance == nullptr)
        instance = new Circuit();
    return instance;
}

nts::Circuit::~Circuit()
{
    for (auto &component : _components)
        delete component.first;
}

void nts::Circuit::addComponent(nts::IComponent &component)
{
    if (_components.find(&component) != _components.end())
        throw Error("Component already exists");
    for (auto &comp : _components)
        if (comp.first->getName() == component.getName())
            throw Error("Component name already taken");
    _components[&component] = std::map<Type, std::vector<std::pair<size_t, nts::IComponent *>>>();
    _components[&component][Type::INPUT] = std::vector<std::pair<size_t, nts::IComponent *>>();
    _components[&component][Type::OUTPUT] = std::vector<std::pair<size_t, nts::IComponent *>>();
}

void nts::Circuit::setLink(nts::IComponent &component, std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    nts::Circuit::Type type = nts::Circuit::Type::INPUT;

    if (_components.find(&component) == _components.end())
        throw Error(component.getName() + " doesn't exist");
    if (_components.find(&other) == _components.end())
        throw Error(other.getName() + " doesn't exist");
    if (!component.isOutput(pin) && !component.isInput(pin))
        throw Error(std::to_string(pin) + " is not a valid pin");
    if (!other.isOutput(otherPin) && !other.isInput(otherPin))
        throw Error(std::to_string(otherPin) + " is not a valid pin");
    if (component.isOutput(pin) && other.isOutput(otherPin))
        throw Error("Cannot link two outputs");
    if (component.isInput(pin) && other.isInput(otherPin))
        throw Error("Cannot link two inputs");
    for (auto &link : _components[&component][Type::INPUT])
        if (link.first == pin)
            throw Error(std::to_string(pin) + " input is already linked");

    type = component.isOutput(pin) ? Type::OUTPUT : Type::INPUT;
    _components[&component][type].push_back(std::pair<size_t, nts::IComponent *>(pin, &other));
    type = other.isOutput(otherPin) ? Type::OUTPUT : Type::INPUT;
    _components[&other][type].push_back(std::pair<size_t, nts::IComponent *>(otherPin, &component));
}

nts::Tristate nts::Circuit::compute(nts::IComponent &component, std::size_t pin)
{
    if (_components.find(&component) == _components.end())
        throw Error(component.getName() + " doesn't exist");
    for (auto &link : _components[&component][Type::INPUT])
        if (link.first == pin)
            return link.second->compute(link.first);
    throw Error(std::to_string(pin) + " is not an input");
}

void nts::Circuit::simulate(size_t tick)
{
    _ticks += tick;
    for (auto &component : _components)
        component.first->simulate(tick);
}

nts::IComponent *nts::Circuit::getCompByName(std::string &name)
{
    for (auto &component : _components) {
        if (component.first->getName() == name)
            return component.first;
    }
    return nullptr;
}

void nts::Circuit::setOutput(const std::string& name, nts::Tristate state)
{
    for (auto &component : _components) {
        if (component.first->getName() == name) {
            auto *shellComp = dynamic_cast<AShell *>(component.first);
            if (shellComp == nullptr)
                throw Error("Component " + name + " is not a shell");
            shellComp->setOutput(state);
            return;
        }
    }
    throw Error("Component " + name + " doesn't exist");
}

static bool compareFunction (nts::IComponent *i, nts::IComponent *j)
{
    return (i->getName()<j->getName());
}

void nts::Circuit::display() const
{
    std::cout << "tick: " << _ticks << std::endl;
    std::vector<IComponent *> input;
    std::vector<IComponent *> output;
    nts::Tristate state;
    std::string state_str;

    for (auto &component : _components) {
        if (component.first->getType() == nts::CompType::INPUT
            || component.first->getType() == nts::CompType::CLOCK)
            input.push_back(component.first);
        if (component.first->getType() == nts::CompType::OUTPUT)
            output.push_back(component.first);
    }
    std::sort(input.begin(), input.end(), compareFunction);
    std::sort(output.begin(), output.end(), compareFunction);
    std::cout << "input(s):" << std::endl;
    for (auto &component : input) {
        state = component->compute();
        state_str = state == nts::Tristate::UNDEFINED ? "U" : std::to_string(state);
        std::cout << "  " << component->getName() << ": " << state_str << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &component : output) {
        state = component->compute();
        state_str = state == nts::Tristate::UNDEFINED ? "U" : std::to_string(state);
        std::cout << "  " << component->getName() << ": " << state_str << std::endl;
    }
}
