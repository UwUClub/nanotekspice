//
// Created by Beafowl on 15/02/23.
//

#ifndef NANOTEKSPICE_ADD_HPP
#define NANOTEKSPICE_ADD_HPP

#include "AComposedComponent.hpp"

namespace nts::component
{
    class Add final : public nts::AComposedComponent {
        public:
            Add();

            nts::Tristate compute(std::size_t pin = 1) final;
        private:
            std::pair<nts::Tristate, nts::Tristate> getTruthTableOutput(nts::Tristate a, nts::Tristate b, nts::Tristate c);
    };
} // namespace nts

#endif //NANOTEKSPICE_ADD_HPP
