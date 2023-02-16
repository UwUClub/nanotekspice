//
// Created by Beafowl on 2/9/23.
//

#include <iostream>
#include <unordered_map>
#include <functional>
#include "Handler.hpp"
#include "Error.hpp"
#include "AShell.hpp"
#include "IComponent.hpp"

nts::Handler::Handler() : _ticks(0)
{
}

nts::Handler::~Handler()
{
    for (auto &it : _components)
        delete it.second;
}

void nts::Handler::handleOutput(std::string &name, std::string &state, const std::string &line)
{
    std::unordered_map<std::string, std::function<void()>> map = {
            {"0", [&] { setOutput(name, nts::FALSE); }},
            {"1", [&] { setOutput(name, nts::TRUE); }},
            {"U", [&] { setOutput(name, nts::UNDEFINED); }},
    };
    name = line.substr(0, line.find('='));
    state = line.substr(line.find('=') + 1, line.size());
    if (map.find(state) != map.end())
        map[state]();
    else
        std::cerr << "Invalid State" << std::endl;
}

void nts::Handler::setOutput(const std::string &name, nts::Tristate state)
{
    if (_components.find(name) == _components.end())
        throw Error("Component doesn't exist");
    auto component = dynamic_cast<nts::AShell *>(_components[name]);
    if (component == nullptr)
        throw Error("Component is not an input or clock");
    component->setOutput(state);
}

void nts::Handler::loop()
{
    while (true) {
        simulate(1);
        display();
    }
}

void nts::Handler::simulate(size_t tick)
{
    _ticks += tick;
    for (auto &it : _components) {
        auto component = dynamic_cast<nts::AShell *>(it.second);
        if (component != nullptr)
            component->simulate(tick);
    }
}

void nts::Handler::runLoop()
{
    std::string line;
    std::string name;
    std::string state;
    bool getting_input = true;
    std::unordered_map<std::string, std::function<void()>> map = {
            {"simulate", [&] { simulate(1); }},
            {"display", [&] { display(); }},
            {"loop", [&] { loop(); }},
            {"exit", [&getting_input] { getting_input = false; }},
    };

    std::cout << "> ";
    while (std::cin >> line) {
        if (map.find(line) != map.end())
            map[line]();
        else if (line.find('=') != std::string::npos)
            handleOutput(name, state, line);
        else
            std::cout << "Invalid Command" << std::endl;
        if (!getting_input)
            break;
        std::cout << "> ";
    }
}

void nts::Handler::addComponent(const std::string &name, IComponent *component)
{
    if (_components.find(name) != _components.end())
        throw Error("Component already exists");
    _components[name] = component;
}

nts::IComponent *nts::Handler::getComponent(const std::string &name)
{
    if (_components.find(name) == _components.end())
        throw Error("Component doesn't exist");
    return _components[name];
}

const std::string &nts::Handler::getComponentName(IComponent *component)
{
    for (auto &it : _components) {
        if (it.second == component)
            return it.first;
    }
    throw Error("Component doesn't exist");
}

void nts::Handler::display() const
{
    nts::Tristate state;
    std::string state_str;

    std::cout << "tick: " << _ticks << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &component : _components) {
        if (component.second->getType() != "input" && component.second->getType() != "clock")
            continue;
        state = component.second->compute();
        state_str = state == nts::Tristate::UNDEFINED ? "U" : std::to_string(state);
        std::cout << "  " << component.first << ": " << state_str << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &component : _components) {
        if (component.second->getType() != "output")
            continue;
        state = component.second->compute();
        state_str = state == nts::Tristate::UNDEFINED ? "U" : std::to_string(state);
        std::cout << "  " << component.first << ": " << state_str << std::endl;
    }
}
