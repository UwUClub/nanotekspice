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
#include "True.hpp"
#include "False.hpp"
#include "Factory.hpp"
#include "Circuit.hpp"

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

static nts::IComponent *createInput(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{}, {1}}
    };
    return new nts::component::Input(name, pins);
}

static nts::IComponent *createOutput(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1}, {}}
    };
    return new nts::component::Output(name, pins);
}

static nts::IComponent *createRom(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2, 3, 4, 5, 6, 7, 8}, {9}}
    };
    return new nts::component::Rom(name, pins);
}

nts::IComponent *nts::Factory::createComponent(const CompType &type, const std::string &name)
{
    std::unordered_map<CompType, std::function<nts::IComponent *()>> components = {
        {CompType::AND, [name] { return createAnd(name); }},
        {CompType::INPUT, [name] { return createInput(name); }},
        {CompType::OUTPUT, [name] { return createOutput(name); }},
        {CompType::ROM, [name] { return createRom(name); }},
        {CompType::AND, [name] { return createAnd(name); }},
        {CompType::TRUE, [name] { return createTrue(name); }},
        {CompType::FALSE, [name] { return createFalse(name); }}
    };
    return components[type]();
}
