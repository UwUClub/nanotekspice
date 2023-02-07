/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Factory
*/

#include <unordered_map>
#include <functional>
#include "And.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Factory.hpp"

static nts::IComponent *createAnd(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}}
    };
    return new nts::component::And(name, pins);
}

static nts::IComponent *createTrue(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{}, {1}}
    };
    return new nts::component::True(name, pins);
}

static nts::IComponent *createFalse(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{}, {1}}
    };
    return new nts::component::False(name, pins);
}

nts::IComponent *nts::Factory::createComponent(const CompType &type, const std::string &name)
{
    static std::unordered_map<CompType, std::function<nts::IComponent *()>> components = {
        {CompType::AND, std::bind(createAnd, name)},
        {CompType::TRUE, std::bind(createTrue, name)},
        {CompType::FALSE, std::bind(createFalse, name)}
    };
    return components[type]();
}
