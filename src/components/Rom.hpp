//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_ROM_HPP
#define NANOTEKSPICE_ROM_HPP

#include "AComponent.hpp"

namespace component
{
    class Rom : public nts::AComponent {
        public:
            Rom() : nts::AComponent("Rom", {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, {16}) { std::cout << "/* create rom */" << std::endl;}
            nts::Tristate compute(std::size_t pin = 1) override { return nts::UNDEFINED; }
            void simulate(std::size_t tick) override {}
        protected:
        private:
    };
} // namespace component

#endif //NANOTEKSPICE_ROM_HPP
