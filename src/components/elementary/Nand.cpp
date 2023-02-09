/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nand
*/

#include "Nand.hpp"

nts::component::Nand::Nand(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::NOR;
}

nts::Tristate nts::component::Nand::compute(std::size_t pin)
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
    if (output == nts::UNDEFINED)
        output = nts::UNDEFINED;
    else
        output = output == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}
