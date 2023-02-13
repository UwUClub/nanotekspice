/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4081
*/

#include "And.hpp"
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

    auto first = it->first[0];
    auto second = it->first[1];

    output = nts::component::Gate4081::compute(_inputs[first], _inputs[second]);
    _outputs[pin] = output;
    return output;
}

nts::Tristate nts::component::Gate4081::compute(nts::Tristate a, nts::Tristate b)
{
    return nts::component::And::compute(a, b);
}
