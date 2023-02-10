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
    _index = 0;
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
    // _index++;
    nts::Tristate output = nts::UNDEFINED;
    auto it = computeInput(13);
    auto it2 = computeInput(12);
    auto it3 = computeInput(11);
    auto it4 = computeInput(10);

    // auto first = _inputs[it->first[0]];
    // auto second = _inputs[it->first[1]];
    // auto third = it->first.size() != 3 ? compute(pin - 1) : _inputs[it->first[2]];
    // auto res = calc(_inputs[first], _inputs[second], _inputs[third]);

    // output = res.first;
    // _outputs[pin] = output;
    // if (_index != 1) {
    //     _index--;
    //     return res.second;
    // }
    // _index = 0;
    return _outputs[pin];
}