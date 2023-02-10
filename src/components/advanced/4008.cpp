/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4008
*/

#include <algorithm>
#include "4008.hpp"

nts::component::Gate4008::Gate4008(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4008;
}

static std::pair<nts::Tristate, nts::Tristate> calc(nts::Tristate first, nts::Tristate second, nts::Tristate third)
{
    if (first == nts::UNDEFINED || second == nts::UNDEFINED || third == nts::UNDEFINED)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::UNDEFINED, nts::UNDEFINED);
    if (first == nts::FALSE && second == nts::FALSE && third == nts::FALSE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::FALSE, nts::FALSE);
    if (first == nts::TRUE && second == nts::FALSE && third == nts::FALSE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::FALSE, nts::TRUE);
    if (first == nts::FALSE && second == nts::TRUE && third == nts::FALSE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::FALSE, nts::TRUE);
    if (first == nts::TRUE && second == nts::TRUE && third == nts::FALSE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::TRUE, nts::FALSE);
    if (first == nts::FALSE && second == nts::FALSE && third == nts::TRUE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::FALSE, nts::TRUE);
    if (first == nts::TRUE && second == nts::FALSE && third == nts::TRUE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::TRUE, nts::FALSE);
    if (first == nts::FALSE && second == nts::TRUE && third == nts::TRUE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::TRUE, nts::FALSE);
    if (first == nts::TRUE && second == nts::TRUE && third == nts::TRUE)
        return std::make_pair<nts::Tristate, nts::Tristate>(nts::TRUE, nts::TRUE);
    return std::make_pair<nts::Tristate, nts::Tristate>(nts::UNDEFINED, nts::UNDEFINED);
}

nts::Tristate nts::component::Gate4008::compute(std::size_t pin)
{
    std::pair<nts::Tristate, nts::Tristate>  res;
    nts::Tristate output = nts::UNDEFINED;
    nts::Tristate third = nts::FALSE;

    for (auto it = _pins.rbegin(); it != _pins.rend(); it++) {
        auto inputs = computeInputs(it->second[0]);
        auto first = _inputs[inputs->first[0]];
        auto second = _inputs[inputs->first[1]];
        if (it == _pins.rbegin())
            third = _inputs[inputs->first[2]];
        auto res = calc(first, second, third);
        output = res.first;
        third = res.second;
        _outputs[it->second[0]] = output;
        _outputs[14] = third;
        if (it->second[0] == pin)
            return output;
    }
    return output;
}
