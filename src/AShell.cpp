/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AShell
*/

#include "AShell.hpp"

nts::AShell::AShell(const std::string &name, const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>& pins) : nts::AComponent(name, pins)
{
    _temp = nts::UNDEFINED;
    _state = State::UPTODATE;
    for (auto &pin : pins)
        for (auto &output : pin.second)
            _outputs[output] = nts::UNDEFINED;
}

void nts::AShell::setOutput(nts::Tristate state)
{
    _temp = state;
    _state = State::TOUPDATE;
}
