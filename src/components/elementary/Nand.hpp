/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nand
*/

#ifndef NAND_HPP_
#define NAND_HPP_

#include "AComponent.hpp"
#include "AComposedComponent.hpp"

namespace nts::component
{
    class Nand final : public nts::AComposedComponent {
        public:
            Nand();

            nts::Tristate compute(std::size_t pin = 1) final;
    };
} // namespace nts


#endif /* !NAND_HPP_ */
