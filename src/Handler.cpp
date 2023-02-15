//
// Created by Beafowl on 2/9/23.
//

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

static void handle_output(std::string &name, std::string &state, const std::string &line)
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
        std::cout << "Invalid State" << std::endl;
}

void nts::Handler::runLoop(nts::Handler handler)
{
    std::string line;
    std::string name;
    std::string state;
    bool getting_input = true;
    std::unordered_map<std::string, std::function<void()>> map = {
            {"simulate", [&] { handler.simulate(1); }},
            {"display", [&] { handler.display(); }},
            {"loop", [&] { loop(); }},
            {"exit", [&getting_input] { getting_input = false; }},
    };

    std::cout << "> ";
    while (std::cin >> line) {
        if (map.find(line) != map.end())
            map[line]();
        else if (line.find('=') != std::string::npos)
            handle_output(name, state, line);
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
