/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#include "Input.hpp"

nts::component::Input::Input(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins)
{
    _type = nts::CompType::INPUT;
    for (auto &pin : pins)
        for (auto &output : pin.second)
            _outputs[output] = nts::UNDEFINED;
}

nts::component::Input::~Input()
{
}
