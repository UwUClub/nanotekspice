/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Output
*/

#include "Output.hpp"

nts::component::Output::Output(const std::string &name, const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins)
{
    _type = nts::CompType::OUTPUT;
}

nts::Tristate nts::component::Output::compute(std::size_t pin)
{
    nts::Tristate output = nts::TRUE;
    auto it = computeInputs(pin);

    for (auto &input : it->first) {
        output = _inputs[input];
    }
    _outputs[pin] = output;
    return output;
}

void nts::component::Output::simulate(std::size_t tick) {}
