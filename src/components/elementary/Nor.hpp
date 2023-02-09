/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nor
*/

#ifndef NOR_HPP_
#define NOR_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Nor : public nts::AComponent {
        public:
            Nor(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
        protected:
        private:
    };
} // namespace nts

#endif /* !NOR_HPP_ */
