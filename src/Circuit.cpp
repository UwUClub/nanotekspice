/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Error.hpp"
#include "AShell.hpp"

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

    if (component.isOutput(pin))
        _components[&component][Type::OUTPUT].push_back(std::pair<size_t, nts::IComponent *>(pin, &other));
    else
        _components[&component][Type::INPUT].push_back(std::pair<size_t, nts::IComponent *>(pin, &other));
    if (other.isOutput(otherPin))
        _components[&other][Type::OUTPUT].push_back(std::pair<size_t, nts::IComponent *>(otherPin, &component));
    else
        _components[&other][Type::INPUT].push_back(std::pair<size_t, nts::IComponent *>(otherPin, &component));
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

nts::IComponent *nts::Circuit::getCompByName(std::string &name) {
    for (auto &component : _components) {
        if (component.first->getName() == name)
            return component.first;
    }
    return nullptr;
}

void nts::Circuit::setOutput(const std::string& name, nts::Tristate state) {
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
