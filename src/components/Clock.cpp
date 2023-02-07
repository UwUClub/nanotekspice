/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Clock
*/

#include "Clock.hpp"

nts::component::Clock::Clock(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins)
{
    _type = nts::CompType::CLOCK;
    for (auto &pin : pins)
        for (auto &output : pin.second)
            _outputs[output] = nts::UNDEFINED;
}

nts::component::Clock::~Clock()
{
}

nts::Tristate nts::component::Clock::compute(std::size_t pin)
{
    if (pin > _outputs.size())
        return nts::UNDEFINED;
    return _outputs[pin];
}

void nts::component::Clock::simulate(std::size_t tick)
{

}
