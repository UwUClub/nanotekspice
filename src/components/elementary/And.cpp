/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And.cpp
*/

#include <algorithm>
#include "And.hpp"
#include "Circuit.hpp"
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

    auto &inputs = it->first;

    auto first = inputs[0];
    auto second = inputs[1];

    output = nts::component::And::compute(_inputs[first], _inputs[second]);
    _outputs[pin] = output;
    return output;
}

nts::Tristate nts::component::And::compute(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::FALSE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}
