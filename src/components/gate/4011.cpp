/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4011
*/

#include "Nand.hpp"
#include "4011.hpp"

nts::component::Gate4011::Gate4011() : AComposedComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[5] = std::make_pair(nullptr, 0);
    _inputs[6] = std::make_pair(nullptr, 0);
    _inputs[8] = std::make_pair(nullptr, 0);
    _inputs[9] = std::make_pair(nullptr, 0);
    _inputs[12] = std::make_pair(nullptr, 0);
    _inputs[13] = std::make_pair(nullptr, 0);
}

nts::Tristate nts::component::Gate4011::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);

    auto first = it->first[0];
    auto second = it->first[1];

    output = nts::component::Gate4011::compute(_inputs[first], _inputs[second]);
    _outputs[pin] = output;
    return output;
}

nts::Tristate nts::component::Gate4011::compute(nts::Tristate a, nts::Tristate b)
{
    nts::Tristate output = nts::FALSE;

    output = nts::component::Nand::compute(a, b);
    return output;
}
