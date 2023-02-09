/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nand
*/

#ifndef NAND_HPP_
#define NAND_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Nand : public nts::AComponent {
        public:
            Nand(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};
        protected:
        private:
    };
} // namespace nts


#endif /* !NAND_HPP_ */
