/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"

namespace nts {
    enum class CompType {
        INPUT,
        OUTPUT,
        CLOCK,
        TRUE,
        FALSE,
        AND,
        OR,
        XOR,
        NOR,
        NAND,
        NOT,
        BUFFER,
        LINK,
        CHIPSET,
        CIRCUIT,
        UNDEFINED
    };

    class Factory {
        public:
            static IComponent *createComponent(const CompType &type);
    };
}

#endif /* !FACTORY_HPP_ */
