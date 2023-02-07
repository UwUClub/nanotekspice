//
// Created by patatofour on 07/02/23.
//

#include <algorithm>
#include "True.hpp"
#include "Error.hpp"

nts::component::True::True(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
}

nts::Tristate nts::component::True::compute(std::size_t pin)
{
    _outputs[pin] = nts::TRUE;
    return nts::TRUE;
}
