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
        class True final : public nts::AComponent {
            public:
            True();

            nts::Tristate compute(std::size_t pin = 1) final;
        };
    } // namespace component
}
#endif // UWUNANO_TRUE_HPP
