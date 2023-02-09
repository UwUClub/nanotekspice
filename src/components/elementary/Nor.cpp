/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nor
*/

#include "Nor.hpp"

nts::component::Nor::Nor(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::NOR;
}

nts::Tristate nts::component::Nor::compute(std::size_t pin)
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
    if (output == nts::UNDEFINED)
        output = nts::UNDEFINED;
    else
        output = output == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}
