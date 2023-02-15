/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4081
*/

#include "And.hpp"
#include "4081.hpp"
#include "Error.hpp"

nts::component::Gate4081::Gate4081() : nts::AComposedComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[5] = std::make_pair(nullptr, 0);
    _inputs[6] = std::make_pair(nullptr, 0);
    _inputs[8] = std::make_pair(nullptr, 0);
    _inputs[9] = std::make_pair(nullptr, 0);
    _inputs[12] = std::make_pair(nullptr, 0);
    _inputs[13] = std::make_pair(nullptr, 0);

    _outputs[3] = std::vector<nts::IComponent *>();
    _outputs[4] = std::vector<nts::IComponent *>();
    _outputs[10] = std::vector<nts::IComponent *>();
    _outputs[11] = std::vector<nts::IComponent *>();

    _subComponents.push_back(nts::Factory::createComponent("and"));
    _subComponents.push_back(nts::Factory::createComponent("and"));
    _subComponents.push_back(nts::Factory::createComponent("and"));
    _subComponents.push_back(nts::Factory::createComponent("and"));

    _subComponents[0]->setInput(1, this, 1);
    _subComponents[0]->setInput(2, this, 2);
    _subComponents[1]->setInput(1, this, 5);
    _subComponents[1]->setInput(2, this, 6);
    _subComponents[2]->setInput(1, this, 8);
    _subComponents[2]->setInput(2, this, 9);
    _subComponents[3]->setInput(1, this, 12);
    _subComponents[3]->setInput(2, this, 13);
}

nts::Tristate nts::component::Gate4081::compute(std::size_t pin)
{
    if (pin == 3)
        return _subComponents[0]->compute(3);
    if (pin == 4)
        return _subComponents[1]->compute(3);
    if (pin == 10)
        return _subComponents[2]->compute(3);
    if (pin == 11)
        return _subComponents[3]->compute(3);
    throw Error("Invalid pin");
}
