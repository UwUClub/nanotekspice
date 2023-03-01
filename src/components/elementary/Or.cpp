/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#include "Or.hpp"
#include "Error.hpp"

nts::component::Or::Or() : nts::AComponent(), _counter(0)
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _outputs[3] = std::vector<nts::IComponent *>();

    _type = "or";
}

nts::Tristate nts::component::Or::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    if (pin != 3)
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    if (_inputs[1].first == nullptr || _inputs[2].first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked for or");
    _counter += 1;

    // should handle the sequential case
    if (_counter > 1) {
        if (_counter > 2)
            return getSeqState(_inputs[2].first->compute(_inputs[2].second));
        return getSeqState(_inputs[1].first->compute(_inputs[1].second));
    }
    nts::Tristate a = _inputs[1].first->compute(_inputs[1].second);
    nts::Tristate b = _inputs[2].first->compute(_inputs[2].second);

    _counter = 0;

    output = getTruthTableOutput(a, b);
    return output;
}

nts::Tristate nts::component::Or::getTruthTableOutput(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::TRUE || b == nts::TRUE)
        return nts::TRUE;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    return nts::FALSE;
}

nts::Tristate nts::component::Or::getSeqState(nts::Tristate a)
{
    if (a == nts::UNDEFINED)
        return nts::UNDEFINED;
    return a == nts::FALSE ? nts::TRUE : nts::FALSE;
}