/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4512
*/

#include <iostream>
#include <string>
#include "4512.hpp"
#include "Error.hpp"

nts::component::Gate4512::Gate4512() : nts::AComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[3] = std::make_pair(nullptr, 0);
    _inputs[4] = std::make_pair(nullptr, 0);
    _inputs[5] = std::make_pair(nullptr, 0);
    _inputs[6] = std::make_pair(nullptr, 0);
    _inputs[7] = std::make_pair(nullptr, 0);
    _inputs[9] = std::make_pair(nullptr, 0);

    _inputs[10] = std::make_pair(nullptr, 0);
    _inputs[11] = std::make_pair(nullptr, 0);
    _inputs[12] = std::make_pair(nullptr, 0);
    _inputs[13] = std::make_pair(nullptr, 0);
    _inputs[15] = std::make_pair(nullptr, 0);

    _outputs[14] = std::vector<IComponent *>{};

    _type = "4512";
}

nts::Tristate nts::component::Gate4512::compute(std::size_t pin)
{
    if (pin != 14)
        throw nts::Error("Pin " + std::to_string(pin));

    nts::Tristate a = _inputs[11].first->compute(_inputs[11].second);
    nts::Tristate b = _inputs[12].first->compute(_inputs[12].second);
    nts::Tristate c = _inputs[13].first->compute(_inputs[13].second);

    nts::Tristate inhibit = _inputs[10].first->compute(_inputs[10].second);
    nts::Tristate enable = _inputs[15].first->compute(_inputs[15].second);

    if (inhibit == nts::TRUE && enable == nts::FALSE)
        return nts::FALSE;
    if (enable == nts::TRUE)
        return nts::UNDEFINED; // might be to change
    if (c == nts::FALSE && b == nts::FALSE && a == nts::FALSE)
        return _inputs[1].first->compute(_inputs[1].second);
    if (c == nts::FALSE && b == nts::FALSE && a == nts::TRUE)
        return _inputs[2].first->compute(_inputs[2].second);
    if (c == nts::FALSE && b == nts::TRUE && a == nts::FALSE)
        return _inputs[3].first->compute(_inputs[3].second);
    if (c == nts::FALSE && b == nts::TRUE && a == nts::TRUE)
        return _inputs[4].first->compute(_inputs[4].second);
    if (c == nts::TRUE && b == nts::FALSE && a == nts::FALSE)
        return _inputs[5].first->compute(_inputs[5].second);
    if (c == nts::TRUE && b == nts::FALSE && a == nts::TRUE)
        return _inputs[6].first->compute(_inputs[6].second);
    if (c == nts::TRUE && b == nts::TRUE && a == nts::FALSE)
        return _inputs[7].first->compute(_inputs[7].second);
    if (c == nts::TRUE && b == nts::TRUE && a == nts::TRUE)
        return _inputs[9].first->compute(_inputs[9].second);
    return nts::UNDEFINED;
}
