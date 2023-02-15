/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Nor
*/

#include "Or.hpp"
#include "Not.hpp"
#include "Nor.hpp"
#include "Error.hpp"

nts::component::Nor::Nor() : nts::AComposedComponent()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _outputs[3] = std::vector<nts::IComponent *>();

    _subComponents.push_back(nts::Factory::createComponent("or"));
    _subComponents.push_back(nts::Factory::createComponent("not"));

    _subComponents[0]->setInput(1, this, 1);
    _subComponents[0]->setInput(2, this, 2);
    _subComponents[1]->setLink(1, *_subComponents[0], 3);
}

nts::Tristate nts::component::Nor::compute(std::size_t pin)
{
    nts::Tristate output = nts::FALSE;
    if (pin != 3)
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    if (_inputs[1].first == nullptr || _inputs[2].first == nullptr)
        throw Error("Pin " + std::to_string(pin) + " is not linked");
    output = _subComponents[1]->compute(2);
    return output;
}
