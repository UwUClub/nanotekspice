/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#ifndef XOR_HPP_
#define XOR_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Xor : public nts::AComponent {
        public:
            Xor(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};

            static nts::Tristate compute(nts::Tristate a, nts::Tristate b);
        protected:
        private:
    };
} // namespace nts

#endif /* !XOR_HPP_ */
