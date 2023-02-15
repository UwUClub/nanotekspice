/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And.cpp
*/

#include <algorithm>
#include "Not.hpp"
#include "Error.hpp"

nts::component::Not::Not() : nts::AComponent()
{
    _inputs[1] = std::pair<nts::IComponent *, std::size_t>(nullptr, 0);
    _outputs[2] = std::vector<nts::IComponent *>();
}

nts::Tristate nts::component::Not::compute(std::size_t pin)
{
    nts::Tristate output = nts::TRUE;
    if (pin != 2)
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    if (_inputs[1].first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked");

    nts::Tristate a = _inputs[1].first->compute(_inputs[1].second);

    if (a == nts::UNDEFINED)
        return nts::UNDEFINED;
    return a == nts::FALSE ? nts::TRUE : nts::FALSE;
}
