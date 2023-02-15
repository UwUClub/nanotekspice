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
#include "4008.hpp"
#include "4013.hpp"
#include "4512.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Factory.hpp"
#include "Clock.hpp"
#include "Or.hpp"
#include "Xor.hpp"
#include "Not.hpp"

nts::IComponent *nts::Factory::createComponent(const CompType &type, const std::string &name)
{
    std::unordered_map<CompType, std::function<nts::IComponent *()>> components = {
        {CompType::INPUT, [name] { return new nts::component::Input(name); }},
        {CompType::OUTPUT, [name] { return new nts::component::Output(name); }},
        {CompType::TRUE, [name] { return new nts::component::True(name); }},
        {CompType::FALSE, [name] { return new nts::component::False(name); }},
        {CompType::CLOCK, [name] { return new nts::component::Clock(name); }},
        {CompType::AND, [name] { return new nts::component::And(name); }},
        {CompType::OR, [name] { return new nts::component::Or(name); }},
        {CompType::XOR, [name] { return new nts::component::Xor(name); }},
        {CompType::NOT, [name] { return new nts::component::Not(name); }},
        {CompType::GATE_4001, [name] { return new nts::component::Gate4001(name);}},
        {CompType::GATE_4011, [name] { return new nts::component::Gate4011(name);}},
        {CompType::GATE_4030, [name] { return new nts::component::Gate4030(name);}},
        {CompType::GATE_4069, [name] { return new nts::component::Gate4069(name);}},
        {CompType::GATE_4071, [name] { return new nts::component::Gate4071(name);}},
        {CompType::GATE_4081, [name] { return new nts::component::Gate4081(name);}},
        {CompType::GATE_4008, [name] { return new nts::component::Gate4008(name);}},
        {CompType::GATE_4013, [name] { return new nts::component::Gate4013(name);}},
        {CompType::GATE_4512, [name] { return new nts::component::Gate4512(name);}},
    };
    return components[type]();
}
