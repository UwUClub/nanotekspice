/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#include "Input.hpp"

nts::component::Input::Input() : nts::AShell()
{
    _outputs[1] = std::vector<nts::IComponent *>();

    _type = "input";
    _currVal = nts::UNDEFINED;
}

nts::Tristate nts::component::Input::compute(std::size_t pin)
{
    return _currVal;
}

void nts::component::Input::simulate(std::size_t tick)
{
    if (_state == State::TOUPDATE) {
        _currVal = _nextVal;
        _state = State::UPTODATE;
    }
}
