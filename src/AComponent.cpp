/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Graph.hpp"

nts::AComponent::AComponent(std::string const &name, std::vector<std::size_t> nbPinsIn, std::vector<std::size_t> nbPinsOut)
    : _name(name)
{
    for (auto &pin : nbPinsIn)
        _inputs[pin] = nts::UNDEFINED;
    for (auto &pin : nbPinsOut)
        _outputs[pin] = nts::UNDEFINED;
}

nts::AComponent::~AComponent()
{
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    Graph *graph = Graph::getInstance();

    if (pin > _outputs.size() || otherPin > other.getNbPinsIn())
        return;
    graph->setLink(*this, pin, other, otherPin);
}

int nts::AComponent::getNbPinsIn() const
{
    return _inputs.size();
}

int nts::AComponent::getNbPinsOut() const
{
    return _outputs.size();
}

bool nts::AComponent::isInput(std::size_t pin) const
{
    return _inputs.find(pin) != _inputs.end();
}

bool nts::AComponent::isOutput(std::size_t pin) const
{
    return _outputs.find(pin) != _outputs.end();
}

const std::string &nts::AComponent::getName() const
{
    return _name;
}
