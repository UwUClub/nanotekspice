/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Graph
*/

#include "Graph.hpp"
#include "Error.hpp"

nts::Graph *nts::Graph::getInstance()
{
    static Graph *instance = nullptr;

    if (instance == nullptr)
        instance = new Graph();
    return instance;
}

nts::Graph::~Graph()
{
    for (auto &component : _components)
        delete component.first;
}

void nts::Graph::addComponent(nts::IComponent &component)
{
    if (_components.find(&component) != _components.end())
        throw Error("Component already exists");
    _components[&component] = std::map<Type, std::vector<std::pair<size_t, nts::IComponent *>>>();
    _components[&component][Type::INPUT] = std::vector<std::pair<size_t, nts::IComponent *>>();
    _components[&component][Type::OUTPUT] = std::vector<std::pair<size_t, nts::IComponent *>>();
}

void nts::Graph::setLink(nts::IComponent &component, std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (_components.find(&component) == _components.end())
        throw Error(component.getName() + " doesn't exist");
    if (_components.find(&other) == _components.end())
        throw Error(other.getName() + " doesn't exist");
    if (!component.isOutput(pin))
        throw Error(std::to_string(pin) + " is not an output");
    if (!other.isInput(otherPin))
        throw Error(std::to_string(otherPin) + " is not an input");

    for (auto &link : _components[&component][Type::OUTPUT])
        if (link.first == pin && link.second == &other)
            throw Error("Link already exists");
    _components[&component][Type::OUTPUT].push_back(std::pair<size_t, nts::IComponent *>(pin, &other));
    _components[&other][Type::INPUT].push_back(std::pair<size_t, nts::IComponent *>(otherPin, &component));
}

nts::Tristate nts::Graph::compute(nts::IComponent &component, std::size_t pin)
{
    if (_components.find(&component) == _components.end())
        throw Error(component.getName() + " doesn't exist");
    for (auto &link : _components[&component][Type::INPUT])
        if (link.first == pin)
            return link.second->compute(link.first);
    throw Error(std::to_string(pin) + " is not an input");
}