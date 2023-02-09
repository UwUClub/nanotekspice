/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Not : public nts::AComponent {
        public:
            Not(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
        protected:
        private:
    };
} // namespace nts

#endif /* !OR_HPP_ */