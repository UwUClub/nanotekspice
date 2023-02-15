/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AComponent
*/

#include <algorithm>
#include "Error.hpp"
#include "AComponent.hpp"

nts::AComponent::AComponent()
{
    _inputs = std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>>();
    _outputs = std::map<std::size_t, std::vector<nts::IComponent *>>();
}

nts::AComponent::~AComponent()
{
}

void nts::AComponent::simulate(std::size_t tick)
{
}

void nts::AComponent::setInput(std::size_t inputPin, IComponent *outputComp, std::size_t outputPin)
{
    if (_inputs.find(inputPin) == _inputs.end()) {
        throw Error("Pin " + std::to_string(inputPin) + " is not an input");
    }
    _inputs[inputPin] = std::pair<nts::IComponent *, std::size_t>(outputComp, outputPin);
}

void nts::AComponent::setLink(std::size_t outputPin, nts::IComponent &other, std::size_t inputPinOther)
{
    if (_outputs.find(outputPin) == _outputs.end()) {
        throw Error("Pin " + std::to_string(outputPin) + " is not an output");
    }
    _outputs[outputPin].push_back(&other);
    other.setInput(inputPinOther, this, outputPin);
}

inputs_t nts::AComponent::getInputs() const
{
    return _inputs;
}

outputs_t nts::AComponent::getOutputs() const
{
    return _outputs;
}
