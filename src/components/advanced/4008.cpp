/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** 4008
*/

#include <algorithm>
#include "Xor.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "4008.hpp"
#include "Error.hpp"

nts::component::Gate4008::Gate4008()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[3] = std::make_pair(nullptr, 0);
    _inputs[4] = std::make_pair(nullptr, 0);
    _inputs[5] = std::make_pair(nullptr, 0);
    _inputs[6] = std::make_pair(nullptr, 0);
    _inputs[7] = std::make_pair(nullptr, 0);
    _inputs[9] = std::make_pair(nullptr, 0);
    _inputs[15] = std::make_pair(nullptr, 0);

    _outputs[10] = std::vector<nts::IComponent *>();
    _outputs[11] = std::vector<nts::IComponent *>();
    _outputs[12] = std::vector<nts::IComponent *>();
    _outputs[13] = std::vector<nts::IComponent *>();
    _outputs[14] = std::vector<nts::IComponent *>();

    _subComponents.push_back(nts::Factory::createComponent("add"));
    _subComponents.push_back(nts::Factory::createComponent("add"));
    _subComponents.push_back(nts::Factory::createComponent("add"));
    _subComponents.push_back(nts::Factory::createComponent("add"));

    _subComponents[0]->setInput(1, this, 6);
    _subComponents[0]->setInput(2, this, 7);
    _subComponents[0]->setInput(3, this, 9);
    _subComponents[0]->setLink(4, *_subComponents[1], 3);

    _subComponents[1]->setInput(1, this, 4);
    _subComponents[1]->setInput(2, this, 5);
    _subComponents[1]->setLink(4, *_subComponents[2], 3);

    _subComponents[2]->setInput(1, this, 2);
    _subComponents[2]->setInput(2, this, 3);
    _subComponents[2]->setLink(4, *_subComponents[3], 3);

    _subComponents[3]->setInput(1, this, 1);
    _subComponents[3]->setInput(2, this, 15);
}

nts::Tristate nts::component::Gate4008::compute(std::size_t pin)
{
    if (pin == 10)
        return _subComponents[0]->compute(4);
    if (pin == 11)
        return _subComponents[1]->compute(4);
    if (pin == 12)
        return _subComponents[2]->compute(4);
    if (pin == 13)
        return _subComponents[3]->compute(4);
    if (pin == 14)
        return _subComponents[3]->compute(5);
    if (_inputs.find(pin) != _inputs.end())
        return _inputs[pin].first->compute(_inputs[pin].second);
    throw Error("Invalid pin");
}
