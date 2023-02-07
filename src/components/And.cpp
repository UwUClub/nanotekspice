/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And.cpp
*/

#include <algorithm>
#include "And.hpp"
#include "Graph.hpp"
#include "Error.hpp"

nts::component::And::And(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::AND;
}

nts::Tristate nts::component::And::compute(std::size_t pin)
{
    nts::Tristate output = nts::TRUE;
    auto it = computeInputs(pin);

    for (auto &input : it->first) {
        if (_inputs[input] == nts::FALSE) {
            output = nts::FALSE;
            break;
        } else if (_inputs[input] == nts::UNDEFINED)
            output = nts::UNDEFINED;
    }
    _outputs[pin] = output;
    return output;
}
