/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4001
*/

#include "Nor.hpp"
#include "4001.hpp"

nts::component::Gate4001::Gate4001(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4001;
}

nts::Tristate nts::component::Gate4001::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);
    auto first = it->first[0];
    auto second = it->first[1];

    switch (_inputs[first])
    {
        case nts::UNDEFINED:
            switch (_inputs[second])
            {
                case nts::TRUE:
                    output = nts::TRUE;
                    break;
                default:
                    output = nts::UNDEFINED;
                    break;
            }
            break;
        case nts::FALSE:
            output = _inputs[second];
            break;
        default:
            output = nts::TRUE;
            break;
    }
    if (output != nts::UNDEFINED)
        output = output == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}
