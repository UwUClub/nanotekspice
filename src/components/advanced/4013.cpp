//
// Created by Beafowl on 13/02/23.
//

#include "4013.hpp"

nts::component::Gate4013::Gate4013(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins)
{
    _type = nts::CompType::GATE_4013;
}

nts::Tristate nts::component::Gate4013::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    auto it = computeInputs(pin);

    for (auto &input : it->first) {
        if (_inputs[input] == nts::TRUE) {
            output = nts::TRUE;
            break;
        } else if (_inputs[input] == nts::UNDEFINED)
            output = nts::UNDEFINED;
    }
    if (output != nts::UNDEFINED)
        output = output == nts::FALSE ? nts::TRUE : nts::FALSE;
    _outputs[pin] = output;
    return output;
}


