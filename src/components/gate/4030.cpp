/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4030
*/

#include "4030.hpp"

nts::component::Gate4030::Gate4030(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4030;
}

nts::Tristate nts::component::Gate4030::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);
    auto first = it->first[0];
    auto second = it->first[1];

    switch (_inputs[first])
    {
        case nts::UNDEFINED:
            output = nts::UNDEFINED;
            break;
        case nts::FALSE:
            output = _inputs[second];
            break;
        default:
            switch (_inputs[second])
            {
            case nts::UNDEFINED:
                output = nts::UNDEFINED;
                break;
            case nts::FALSE:
                output = nts::TRUE;
                break;
            default:
                output = nts::FALSE;
                break;
            }
    }
    _outputs[pin] = output;
    return output;
}