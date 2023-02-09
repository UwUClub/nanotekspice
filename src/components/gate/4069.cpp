/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4069
*/

#include "4069.hpp"

nts::component::Gate4069::Gate4069(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4069;
}

nts::Tristate nts::component::Gate4069::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);
    auto first = it->first[0];

    if (_inputs[first] != nts::UNDEFINED)
        output = first == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}
