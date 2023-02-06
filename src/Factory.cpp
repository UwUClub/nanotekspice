/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Factory
*/

#include <unordered_map>
#include <functional>
#include "And.hpp"
#include "Factory.hpp"

nts::IComponent *nts::Factory::createComponent(const CompType &type)
{
    static std::unordered_map<CompType, std::function<nts::IComponent *()>> components = {
        {CompType::AND, []() { return new component::And(); }},
    };
    return components[type]();
}
