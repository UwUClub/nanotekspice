/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nor
*/

#include "Or.hpp"
#include "Not.hpp"
#include "Nor.hpp"

nts::component::Nor::Nor(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::NOR;
}

nts::Tristate nts::component::Nor::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);
    auto first = it->first[0];
    auto second = it->first[1];

    output = nts::component::Nor::compute(_inputs[first], _inputs[second]);
    _outputs[pin] = output;
    return output;
}

nts::Tristate nts::component::Nor::compute(nts::Tristate a, nts::Tristate b)
{
    nts::Tristate output = nts::FALSE;

    output = nts::component::Or::compute(a, b);
    return nts::component::Not::compute(output);
}