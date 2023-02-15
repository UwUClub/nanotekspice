/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And.cpp
*/

#include <algorithm>
#include "And.hpp"
#include "Error.hpp"

nts::component::And::And() : nts::AComponent()
{
    _inputs[1] = std::pair<nts::IComponent *, std::size_t>(nullptr, 0);
    _inputs[2] = std::pair<nts::IComponent *, std::size_t>(nullptr, 0);
    _outputs[3] = std::vector<nts::IComponent *>();
}

nts::Tristate nts::component::And::compute(std::size_t pin)
{
    nts::Tristate output = nts::UNDEFINED;
    if (pin != 3)
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    if (_inputs[1].first == nullptr || _inputs[2].first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked");

    nts::Tristate a = _inputs[1].first->compute(_inputs[1].second);
    nts::Tristate b = _inputs[2].first->compute(_inputs[2].second);

    output = getTruthTableOutput(a, b);

    return output;
}

nts::Tristate nts::component::And::getTruthTableOutput(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::FALSE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::TRUE;
}
