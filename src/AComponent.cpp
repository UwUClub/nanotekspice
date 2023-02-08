/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AComponent
*/

#include <algorithm>
#include "Error.hpp"
#include "AComponent.hpp"
#include "Circuit.hpp"

nts::AComponent::AComponent(std::string const &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : _name(name), _pins(pins), _type(nts::CompType::UNDEFINED)
{
    for (auto &pin : pins) {
        for (auto &input : pin.first)
            _inputs[input] = nts::UNDEFINED;
        for (auto &output : pin.second)
            _outputs[output] = nts::UNDEFINED;
    }
}

nts::AComponent::~AComponent()
{
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    Circuit *Circuit = Circuit::getInstance();

    Circuit->setLink(*this, pin, other, otherPin);
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

nts::CompType nts::AComponent::getType() const
{
    return _type;
}

std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>::iterator nts::AComponent::computeInputs(std::size_t pin)
{
    Circuit *Circuit = Circuit::getInstance();

    auto it = std::find_if(_pins.begin(), _pins.end(), [pin](auto &pair) {
        return std::find(pair.second.begin(), pair.second.end(), pin) != pair.second.end();
    });

    if (it == _pins.end()) {
        it = std::find_if(_pins.begin(), _pins.end(), [pin](auto &pair) {
            return std::find(pair.first.begin(), pair.first.end(), pin) != pair.first.end();
        });
    }
    if (it == _pins.end())
        throw Error("Pin not found" + std::to_string(pin));
    for (auto &input : it->first) {
        _inputs[input] = Circuit->compute(*this, input);
    }
    return it;
}