/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#include "Xor.hpp"
#include "Error.hpp"

nts::component::Xor::Xor() : nts::AComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _outputs[3] = std::vector<nts::IComponent *>();
}

nts::Tristate nts::component::Xor::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    if (pin != 3)
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    if (_inputs[1].first == nullptr || _inputs[2].first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked");

    nts::Tristate a = _inputs[1].first->compute(_inputs[1].second);
    nts::Tristate b = _inputs[2].first->compute(_inputs[2].second);

    output = getTruthTableOutput(a, b);
    return output;
}

nts::Tristate nts::component::Xor::getTruthTableOutput(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a == b)
        return nts::FALSE;
    return nts::TRUE;
}