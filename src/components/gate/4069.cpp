/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4069
*/

#include "Not.hpp"
#include "4069.hpp"
#include "Error.hpp"

nts::component::Gate4069::Gate4069() : nts::AComposedComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[3] = std::make_pair(nullptr, 0);
    _inputs[5] = std::make_pair(nullptr, 0);
    _inputs[9] = std::make_pair(nullptr, 0);
    _inputs[11] = std::make_pair(nullptr, 0);
    _inputs[13] = std::make_pair(nullptr, 0);

    _outputs[2] = std::vector<nts::IComponent *>();
    _outputs[4] = std::vector<nts::IComponent *>();
    _outputs[6] = std::vector<nts::IComponent *>();
    _outputs[8] = std::vector<nts::IComponent *>();
    _outputs[10] = std::vector<nts::IComponent *>();
    _outputs[12] = std::vector<nts::IComponent *>();

    _subComponents.push_back(nts::Factory::createComponent("not"));
    _subComponents.push_back(nts::Factory::createComponent("not"));
    _subComponents.push_back(nts::Factory::createComponent("not"));
    _subComponents.push_back(nts::Factory::createComponent("not"));
    _subComponents.push_back(nts::Factory::createComponent("not"));
    _subComponents.push_back(nts::Factory::createComponent("not"));

    _subComponents[0]->setInput(1, this, 1);
    _subComponents[1]->setInput(1, this, 3);
    _subComponents[2]->setInput(1, this, 5);
    _subComponents[3]->setInput(1, this, 9);
    _subComponents[4]->setInput(1, this, 11);
    _subComponents[5]->setInput(1, this, 13);
}

nts::Tristate nts::component::Gate4069::compute(std::size_t pin)
{
    if (pin == 2)
        return _subComponents[0]->compute(2);
    if (pin == 4)
        return _subComponents[1]->compute(2);
    if (pin == 6)
        return _subComponents[2]->compute(2);
    if (pin == 8)
        return _subComponents[3]->compute(2);
    if (pin == 10)
        return _subComponents[4]->compute(2);
    if (pin == 12)
        return _subComponents[5]->compute(2);
    throw Error("Invalid pin");
}
