//
// Created by patatofour on 07/02/23.
//

#ifndef UWUNANO_FALSE_HPP
#define UWUNANO_FALSE_HPP

#include "AComponent.hpp"

namespace nts {
    namespace component {
        class False : public nts::AComponent {
            public:
            False(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);

            nts::Tristate compute(std::size_t pin) override;
            void simulate(std::size_t tick) override {}
        };
    } // namespace component
}

#endif // UWUNANO_FALSE_HPP
