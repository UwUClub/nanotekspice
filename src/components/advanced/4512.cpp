/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4512
*/

#include "4512.hpp"
#include "iostream"
#include "string"

nts::component::Gate4512::Gate4512(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4512;
}

nts::Tristate nts::component::Gate4512::compute(std::size_t pin)
{
    computeInputs(14);

    auto a = _inputs[11];
    auto b = _inputs[12];
    auto c = _inputs[13];

    auto inhibit = _inputs[10];
    auto enable = _inputs[15];

    if (inhibit == nts::TRUE && enable == nts::FALSE)
        return nts::FALSE;
    if (enable == nts::TRUE)
        return nts::UNDEFINED; // might be to change
    if (c == nts::FALSE && b == nts::FALSE && a == nts::FALSE)
        return _inputs[1];
    if (c == nts::FALSE && b == nts::FALSE && a == nts::TRUE)
        return _inputs[2];
    if (c == nts::FALSE && b == nts::TRUE && a == nts::FALSE)
        return _inputs[3];
    if (c == nts::FALSE && b == nts::TRUE && a == nts::TRUE)
        return _inputs[4];
    if (c == nts::TRUE && b == nts::FALSE && a == nts::FALSE)
        return _inputs[5];
    if (c == nts::TRUE && b == nts::FALSE && a == nts::TRUE)
        return _inputs[6];
    if (c == nts::TRUE && b == nts::TRUE && a == nts::FALSE)
        return _inputs[7];
    if (c == nts::TRUE && b == nts::TRUE && a == nts::TRUE)
        return _inputs[9];
    return nts::UNDEFINED;
}
