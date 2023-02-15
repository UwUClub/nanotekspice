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
    class Factory {
        public:
            static IComponent *createComponent(const std::string &type);
    };
}

#endif /* !FACTORY_HPP_ */
