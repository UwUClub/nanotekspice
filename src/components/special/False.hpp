//
// Created by patatofour on 07/02/23.
//

#ifndef UWUNANO_FALSE_HPP
#define UWUNANO_FALSE_HPP

#include "AComponent.hpp"

namespace nts {
    namespace component {
        class False final : public nts::AComponent {
            public:
            False();

            nts::Tristate compute(std::size_t pin) final;
        };
    } // namespace component
}

#endif // UWUNANO_FALSE_HPP
