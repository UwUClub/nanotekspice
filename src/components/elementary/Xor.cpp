/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#include "Xor.hpp"

nts::component::Xor::Xor(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::XOR;
}

nts::Tristate nts::component::Xor::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);
    auto first = it->first[0];
    auto second = it->first[1];

    output = nts::component::Xor::compute(_inputs[first], _inputs[second]);
    _outputs[pin] = output;
    return output;
}

nts::Tristate nts::component::Xor::compute(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a == b)
        return nts::FALSE;
    return nts::TRUE;
}