/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#include "Input.hpp"

nts::component::Input::Input(const std::string &name, const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>& pins) : nts::AShell(name, pins)
{
    _type = nts::CompType::INPUT;
}

nts::Tristate nts::component::Input::compute(std::size_t pin)
{
    return _outputs[pin];
}

void nts::component::Input::simulate(std::size_t tick)
{

}
