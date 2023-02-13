//
// Created by Beafowl on 13/02/23.
//

#ifndef NANOTEKSPICE_4013_HPP
#define NANOTEKSPICE_4013_HPP

#include "AComponent.hpp"

namespace nts::component
{
    class Gate4013 : public nts::AComponent {
        public:
            Gate4013(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
    };
}

#endif //NANOTEKSPICE_4013_HPP
