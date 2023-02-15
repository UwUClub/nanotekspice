//
// Created by Beafowl on 2/9/23.
//

#include "Circuit.hpp"
#include "Handler.hpp"
#include "Error.hpp"
#include <iostream>
#include <unordered_map>
#include <functional>


nts::Handler::Handler() = default;

nts::Handler::~Handler()
{
    for (auto &it : _components)
        delete it.second;
}

[[noreturn]] static void loop(nts::Circuit *Circuit)
{
    while (true) {
        Circuit->simulate(1);
        Circuit->display();
    }
}

static void handle_output(std::string &name, std::string &state, const std::string &line, nts::Circuit *Circuit)
{
    std::unordered_map<std::string, std::function<void()>> map = {
            {"0", [&] { Circuit->setOutput(name, nts::FALSE); }},
            {"1", [&] { Circuit->setOutput(name, nts::TRUE); }},
            {"U", [&] { Circuit->setOutput(name, nts::UNDEFINED); }},
    };
    name = line.substr(0, line.find('='));
    state = line.substr(line.find('=') + 1, line.size());
    if (map.find(state) != map.end())
        map[state]();
    else
        std::cout << "Invalid State" << std::endl;
}

void nts::Handler::runLoop()
{
    Circuit *Circuit = Circuit::getInstance();
    std::string line;
    std::string name;
    std::string state;
    bool getting_input = true;
    std::unordered_map<std::string, std::function<void()>> map = {
            {"simulate", [&] { Circuit->simulate(1); }},
            {"display", [&] { Circuit->display(); }},
            {"loop", [&] { loop(Circuit); }},
            {"exit", [&getting_input] { getting_input = false; }},
    };

    std::cout << "> ";
    while (std::cin >> line) {
        if (map.find(line) != map.end())
            map[line]();
        else if (line.find('=') != std::string::npos)
            handle_output(name, state, line, Circuit);
        else
            std::cout << "Invalid Command" << std::endl;
        if (!getting_input)
            break;
        std::cout << "> ";
    }
}

void nts::Handler::addComponent(std::string name, IComponent *component)
{
    if (_components.find(name) != _components.end())
        throw Error("Component already exists");
    _components[name] = component;
}

nts::IComponent *nts::Handler::getComponent(std::string name)
{
    if (_components.find(name) == _components.end())
        throw Error("Component doesn't exist");
    return _components[name];
}
