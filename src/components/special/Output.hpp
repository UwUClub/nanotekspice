//
// Created by Beafowl on 2/6/23.
//

#ifndef NANOTEKSPICE_OUTPUT_HPP
#define NANOTEKSPICE_OUTPUT_HPP

#include "AComponent.hpp"

namespace nts::component
{
    class Output : public nts::AComponent {
        public:
            Output(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{std::make_pair(std::vector<std::size_t>{1}, std::vector<std::size_t>{})});

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override;

        protected:
        private:
    };
} // namespace component

#endif //NANOTEKSPICE_OUTPUT_HPP
