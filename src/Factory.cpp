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
#include "4001.hpp"
#include "4011.hpp"
#include "4030.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Factory.hpp"
#include "Clock.hpp"
#include "Or.hpp"
#include "Xor.hpp"

static nts::IComponent *createAnd(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}}
    };
    return new nts::component::And(name, pins);
}

static nts::IComponent *createOr(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}}
    };
    return new nts::component::Or(name, pins);
}

static nts::IComponent *createXor(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}}
    };
    return new nts::component::Xor(name, pins);
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

static nts::IComponent *createClock(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{}, {1}}
    };
    return new nts::component::Clock(name, pins);
}

static nts::IComponent *create4001(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}},
        {{5, 6}, {4}},
        {{8, 9}, {10}},
        {{12, 13}, {11}}
    };
    return new nts::component::Gate4001(name, pins);
}

static nts::IComponent *create4011(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}},
        {{5, 6}, {4}},
        {{8, 9}, {10}},
        {{12, 13}, {11}}
    };
    return new nts::component::Gate4011(name, pins);
}

static nts::IComponent *create4030(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}},
        {{5, 6}, {4}},
        {{8, 9}, {10}},
        {{12, 13}, {11}}
    };
    return new nts::component::Gate4030(name, pins);
}

static nts::IComponent *create4069(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1}, {2}},
        {{3}, {4}},
        {{5}, {6}},
        {{9}, {8}},
        {{11}, {10}},
        {{13}, {12}}
    };
    return new nts::component::Gate4069(name, pins);
}

static nts::IComponent *create4071(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}},
        {{5, 6}, {4}},
        {{8, 9}, {10}},
        {{12, 13}, {11}}
    };
    return new nts::component::Gate4071(name, pins);
}

static nts::IComponent *create4081(const std::string &name)
{
    std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins = {
        {{1, 2}, {3}},
        {{5, 6}, {4}},
        {{8, 9}, {10}},
        {{12, 13}, {11}}
    };
    return new nts::component::Gate4081(name, pins);
}

nts::IComponent *nts::Factory::createComponent(const CompType &type, const std::string &name)
{
    std::unordered_map<CompType, std::function<nts::IComponent *()>> components = {
        {CompType::INPUT, [name] { return createInput(name); }},
        {CompType::OUTPUT, [name] { return createOutput(name); }},
        {CompType::TRUE, [name] { return createTrue(name); }},
        {CompType::FALSE, [name] { return createFalse(name); }},
        {CompType::CLOCK, [name] { return createClock(name); }},
        {CompType::AND, [name] { return createAnd(name); }},
        {CompType::OR, [name] { return createOr(name); }},
        {CompType::XOR, [name] { return createXor(name); }},
        {CompType::GATE_4001, [name] { return create4001(name); }},
        {CompType::GATE_4011, [name] { return create4011(name); }},
        {CompType::GATE_4030, [name] { return create4030(name); }},
        {CompType::GATE_4069, [name] { return create4069(name); }},
        {CompType::GATE_4071, [name] { return create4071(name); }},
        {CompType::GATE_4081, [name] { return create4081(name); }}
    };
    return components[type]();
}
