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
#include "Error.hpp"

nts::IComponent *nts::Factory::createComponent(const std::string &type)
{
    std::unordered_map<std::string, std::function<nts::IComponent *()>> components = {
        {"input", [] { return new nts::component::Input(); }},
        {"output", [] { return new nts::component::Output(); }},
        {"true", [] { return new nts::component::True(); }},
        {"false", [] { return new nts::component::False(); }},
        {"clock", [] { return new nts::component::Clock(); }},
        {"and", [] { return new nts::component::And(); }},
        {"or", [] { return new nts::component::Or(); }},
        {"xor", [] { return new nts::component::Xor(); }},
        {"not", [] { return new nts::component::Not(); }},
        // {"4001", [] { return new nts::component::Gate4001();}},
        // {"4011", [] { return new nts::component::Gate4011();}},
        // {"4030", [] { return new nts::component::Gate4030();}},
        // {"4069", [] { return new nts::component::Gate4069();}},
        // {"4071", [] { return new nts::component::Gate4071();}},
        // {"4081", [] { return new nts::component::Gate4081();}},
        // {"4008", [] { return new nts::component::Gate4008();}},
        // {"4013", [] { return new nts::component::Gate4013();}},
        // {"4512", [] { return new nts::component::Gate4512();}},
    };
    if (components.find(type) == components.end())
        throw Error("Component " + type + " does not exist");
    return components[type]();
}
