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
}

nts::Tristate nts::component::Clock::compute(std::size_t pin)
{
    return _outputs[pin];
}

void nts::component::Clock::simulate(std::size_t tick)
{

}
