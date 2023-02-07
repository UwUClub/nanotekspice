//
// Created by patatofour on 07/02/23.
//

#ifndef UWUNANO_TRUE_HPP
#define UWUNANO_TRUE_HPP

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class True : public nts::AComponent {
            public:
            True(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {}

            protected:
            private:
        };
    } // namespace component
}
#endif // UWUNANO_TRUE_HPP
