/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4081
*/

#include "4081.hpp"

nts::component::Gate4081::Gate4081(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4081;
}

nts::Tristate nts::component::Gate4081::compute(std::size_t pin)
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
