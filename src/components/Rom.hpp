//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_ROM_HPP
#define NANOTEKSPICE_ROM_HPP

#include "AComponent.hpp"

namespace nts::component
{
    class Rom : public nts::AComponent {
        public:
            Rom(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins) : nts::AComponent(name, pins) {}

            nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; }
            void simulate(std::size_t tick) override {}
        protected:
        private:
    };
} // namespace component

#endif //NANOTEKSPICE_ROM_HPP
