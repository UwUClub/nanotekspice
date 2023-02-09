/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4011
*/

#include "4011.hpp"

nts::component::Gate4011::Gate4011(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4011;
}

nts::Tristate nts::component::Gate4011::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);

    for (auto &input : it->first) {
        if (_inputs[input] == nts::TRUE) {
            output = nts::TRUE;
            break;
        } else if (_inputs[input] == nts::UNDEFINED)
            output = nts::UNDEFINED;
    }
    if (output != nts::UNDEFINED)
        output = output == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}
