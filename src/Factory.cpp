/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Factory
*/

#include <unordered_map>
#include <functional>
#include "And.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Rom.hpp"
#include "Factory.hpp"

nts::IComponent *nts::Factory::createComponent(const CompType &type)
{
    static std::unordered_map<CompType, std::function<nts::IComponent *()>> components = {
        {CompType::AND, []() { return new component::And(); }},
        {CompType::INPUT, []() { return new component::Input(); }},
        {CompType::OUTPUT, []() { return new component::Output(); }},
        {CompType::ROM, []() { return new component::Rom(); }},
    };
    return components[type]();
}
