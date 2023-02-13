/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nand
*/

#include "And.hpp"
#include "Not.hpp"
#include "Nand.hpp"

nts::component::Nand::Nand(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::NAND;
}

nts::Tristate nts::component::Nand::compute(std::size_t pin)
{
    nts::Tristate output = nts::TRUE;
    auto it = computeInputs(pin);

    auto &inputs = it->first;

    auto first = inputs[0];
    auto second = inputs[1];

    output = nts::component::Nand::compute(_inputs[first], _inputs[second]);
    _outputs[pin] = output;
    return output;
}

nts::Tristate nts::component::Nand::compute(nts::Tristate a, nts::Tristate b)
{
    nts::Tristate output = nts::TRUE;

    output = nts::component::And::compute(a, b);
    return nts::component::Not::compute(output);
}
