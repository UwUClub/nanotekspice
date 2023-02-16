/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Add.cpp
*/

#include "Add.hpp"
#include "Error.hpp"

nts::component::Add::Add() : AComposedComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[3] = std::make_pair(nullptr, 0);

    _outputs[4] = std::vector<nts::IComponent *>();
    _outputs[5] = std::vector<nts::IComponent *>();

    _type = "add";

    _subComponents.push_back(nts::Factory::createComponent("xor")); // 0
    _subComponents.push_back(nts::Factory::createComponent("xor")); // 1
    _subComponents.push_back(nts::Factory::createComponent("and")); // 2
    _subComponents.push_back(nts::Factory::createComponent("and")); // 3
    _subComponents.push_back(nts::Factory::createComponent("or")); // 4

    _subComponents[0]->setInput(1, this, 1);
    _subComponents[0]->setInput(2, this, 2);
    _subComponents[0]->setLink(3, *_subComponents[1], 1);
    _subComponents[0]->setLink(3, *_subComponents[2], 2);

    _subComponents[1]->setInput(2, this, 3);

    _subComponents[2]->setInput(1, this, 3);
    _subComponents[2]->setLink(3, *_subComponents[4], 1);

    _subComponents[3]->setInput(1, this, 1);
    _subComponents[3]->setInput(2, this, 2);
    _subComponents[3]->setLink(3, *_subComponents[4], 2);

}

nts::Tristate nts::component::Add::compute(std::size_t pin)
{
    if (_inputs[1].first == nullptr || _inputs[2].first == nullptr || _inputs[3].first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked for add");

    if (pin == 4)
        return _subComponents[1]->compute(3);
    if (pin == 5)
        return _subComponents[4]->compute(3);
    if (_inputs.find(pin) != _inputs.end())
        return _inputs[pin].first->compute(_inputs[pin].second);
    throw Error("Invalid pin");
}
