/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And.cpp
*/

#include <algorithm>
#include "Not.hpp"

nts::component::Not::Not(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::NOT;
}

nts::Tristate nts::component::Not::compute(std::size_t pin)
{
    nts::Tristate output = nts::TRUE;
    auto it = computeInputs(pin);
    auto first = it->first[0];

    if (_inputs[first] == nts::UNDEFINED)
        output = nts::UNDEFINED;
    else
        output = first == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}
