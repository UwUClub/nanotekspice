//
// Created by patatofour on 07/02/23.
//

#include "False.hpp"
#include "Error.hpp"

nts::component::False::False() : nts::AComponent()
{
    _outputs[1] = std::vector<nts::IComponent *>();
}

nts::Tristate nts::component::False::compute(std::size_t pin)
{
    return nts::FALSE;
}
