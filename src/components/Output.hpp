//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_OUTPUT_HPP
#define NANOTEKSPICE_OUTPUT_HPP

#include "AComponent.hpp"

namespace component
{
    class Output : public nts::AComponent {
        public:
            Output() : nts::AComponent("Output", {0}, {}) { std::cout << "/* create output */" << std::endl;}

            nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; }
            void simulate(std::size_t tick) override {}

        protected:
        private:
    };
} // namespace component

#endif //NANOTEKSPICE_OUTPUT_HPP
