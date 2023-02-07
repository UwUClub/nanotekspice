//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_INPUT_HPP
#define NANOTEKSPICE_INPUT_HPP

#include "AComponent.hpp"

namespace nts::component
{
    class Input : public nts::AComponent {
        public:
            Input(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins) {}

            nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; }
            void simulate(std::size_t tick) override {}

        protected:
        private:
    };
} // namespace component

#endif //NANOTEKSPICE_INPUT_HPP
