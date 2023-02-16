//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_OUTPUT_HPP
#define NANOTEKSPICE_OUTPUT_HPP

#include "AComponent.hpp"

namespace nts::component
{
    class Output final : public nts::AComponent {
        public:
            Output();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace component

#endif //NANOTEKSPICE_OUTPUT_HPP
