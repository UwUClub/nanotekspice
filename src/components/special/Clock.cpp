/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Clock
*/

#include "Clock.hpp"

nts::component::Clock::Clock() : nts::AShell()
{
    _outputs[1] = std::vector<nts::IComponent *>();
    _currVal = nts::UNDEFINED;
    _type = "clock";
}

nts::Tristate nts::component::Clock::compute(std::size_t pin)
{
    return _currVal;
}

void nts::component::Clock::simulate(std::size_t tick)
{
    std::size_t i = 0;

    if (_currVal == nts::UNDEFINED && _state != State::TOUPDATE)
        return;
    if (_state == State::TOUPDATE) {
        _currVal = _nextVal;
        _state = State::UPTODATE;
        i = 1;
    }
    for (; i < tick; i++) {
        _currVal = _currVal == nts::TRUE ? nts::FALSE : nts::TRUE;
    }
}
