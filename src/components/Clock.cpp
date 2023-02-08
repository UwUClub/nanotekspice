/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Clock
*/

#include "Clock.hpp"

nts::component::Clock::Clock(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AShell(name, pins)
{
    _type = nts::CompType::CLOCK;
    _outputs[0] = nts::UNDEFINED;
}

nts::Tristate nts::component::Clock::compute(std::size_t pin)
{
    return _outputs[0];
}

void nts::component::Clock::simulate(std::size_t tick)
{
    std::size_t i = 0;

    if (_state == State::TOUPDATE) {
        _outputs[0] = _temp;
        _state = State::UPTODATE;
        if (tick >= 1)
            i++;
    }
    for (; i < tick; i++) {
        _outputs[0] = _outputs[0] == nts::TRUE ? nts::FALSE : nts::TRUE;
    }
}
