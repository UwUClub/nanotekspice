/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AShell
*/

#include "AShell.hpp"

nts::AShell::AShell() : nts::AComponent()
{
    _nextVal = nts::UNDEFINED;
    _state = State::UPTODATE;
}

void nts::AShell::setOutput(nts::Tristate state)
{
    _nextVal = state;
    _state = State::TOUPDATE;
}
