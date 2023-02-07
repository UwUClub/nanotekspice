//
// Created by patatofour on 07/02/23.
//

#include "False.hpp"
#include "Error.hpp"

nts::component::False::False(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
    _type = nts::CompType::FALSE;
}

nts::Tristate nts::component::False::compute(std::size_t pin)
{
    _outputs[pin] = nts::FALSE;
    return nts::FALSE;
}
