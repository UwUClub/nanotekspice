//
// Created by patatofour on 07/02/23.
//

#include <algorithm>
#include "True.hpp"
#include "Error.hpp"

nts::component::True::True() : nts::AComponent()
{
    _outputs[1] = std::vector<nts::IComponent *>();
}

nts::Tristate nts::component::True::compute(std::size_t pin)
{
    return nts::TRUE;
}
