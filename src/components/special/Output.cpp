/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Output
*/

#include "Output.hpp"
#include "Error.hpp"

nts::component::Output::Output() : nts::AComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);

    _type = "output";
}

nts::Tristate nts::component::Output::compute(std::size_t pin)
{
    nts::Tristate output = nts::TRUE;
    if (pin != 1)
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    auto a = _inputs[1];
    if (a.first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked");

    output = a.first->compute(a.second);
    return output;
}
