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
            Gate4013(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{
                        std::make_pair(std::vector<std::size_t>{3, 4, 5, 6}, std::vector<std::size_t>{1, 2}),
                        std::make_pair(std::vector<std::size_t>{8, 9, 10, 11}, std::vector<std::size_t>{12, 13})
                    });
            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
    };
}

#endif //NANOTEKSPICE_4013_HPP
