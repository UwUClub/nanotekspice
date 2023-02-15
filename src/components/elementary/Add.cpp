/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Add.cpp
*/

#include "Add.hpp"
#include "Error.hpp"

nts::component::Add::Add() : AComposedComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[3] = std::make_pair(nullptr, 0);

    _outputs[4] = std::vector<nts::IComponent *>();
    _outputs[5] = std::vector<nts::IComponent *>();
}

nts::Tristate nts::component::Add::compute(std::size_t pin)
{
       if (pin != 4 && pin != 5)
            throw Error("Pin " + std::to_string(pin) + " is not an output");
        if (_inputs[1].first == nullptr || _inputs[2].first == nullptr || _inputs[3].first == nullptr)
            throw Error("Pin " + std::to_string(pin) + " is not linked");

        nts::Tristate a = _inputs[1].first->compute(_inputs[1].second);
        nts::Tristate b = _inputs[2].first->compute(_inputs[2].second);
        nts::Tristate c = _inputs[3].first->compute(_inputs[3].second);

        std::pair<nts::Tristate, nts::Tristate> output = getTruthTableOutput(a, b, c);
}

std::pair<nts::Tristate, nts::Tristate> nts::component::Add::getTruthTableOutput(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    std::pair<nts::Tristate, nts::Tristate> output;
    if (a == nts::UNDEFINED || b == nts::UNDEFINED || c == nts::UNDEFINED) {
        output.first = nts::UNDEFINED;
        output.second = nts::UNDEFINED;
        return output;
    }
    if (a == nts::TRUE && b == nts::FALSE && c == nts::FALSE) {
        output.first = nts::FALSE;
        output.second = nts::TRUE;
        return output;
    }
    if (a == nts::FALSE && b == nts::TRUE && c == nts::FALSE) {
        output.first = nts::FALSE;
        output.second = nts::TRUE;
        return output;
    }
    if (a == nts::TRUE && b == nts::TRUE && c == nts::FALSE) {
        output.first = nts::TRUE;
        output.second = nts::FALSE;
        return output;
    }
    if (a == nts::FALSE && b == nts::FALSE && c == nts::TRUE) {
        output.first = nts::FALSE;
        output.second = nts::TRUE;
        return output;
    }
    if (a == nts::TRUE && b == nts::FALSE && c == nts::TRUE) {
        output.first = nts::TRUE;
        output.second = nts::FALSE;
        return output;
    }
    if (a == nts::FALSE && b == nts::TRUE && c == nts::TRUE) {
        output.first = nts::TRUE;
        output.second = nts::FALSE;
        return output;
    }
    if (a == nts::TRUE && b == nts::TRUE && c == nts::TRUE) {
        output.first = nts::TRUE;
        output.second = nts::TRUE;
        return output;
    }
    return output;
}
