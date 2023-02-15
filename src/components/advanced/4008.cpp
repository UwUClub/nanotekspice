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

nts::component::Gate4008::Gate4008()
{
    _inputs[1] = std::make_pair(nullptr, 0);
    _inputs[2] = std::make_pair(nullptr, 0);
    _inputs[3] = std::make_pair(nullptr, 0);
    _inputs[4] = std::make_pair(nullptr, 0);
    _inputs[5] = std::make_pair(nullptr, 0);
    _inputs[6] = std::make_pair(nullptr, 0);
    _inputs[7] = std::make_pair(nullptr, 0);
    _inputs[8] = std::make_pair(nullptr, 0);
    _inputs[9] = std::make_pair(nullptr, 0);

    _outputs[10] = std::vector<nts::IComponent *>();
    _outputs[11] = std::vector<nts::IComponent *>();
    _outputs[12] = std::vector<nts::IComponent *>();
    _outputs[13] = std::vector<nts::IComponent *>();
    _outputs[14] = std::vector<nts::IComponent *>();



}

nts::Tristate nts::component::Gate4008::compute(std::size_t pin)
{
    std::pair<nts::Tristate, nts::Tristate>  res;
    nts::Tristate output = nts::UNDEFINED;
    nts::Tristate third = nts::FALSE;

    for (auto it = _pins.rbegin(); it != _pins.rend(); it++) {
        auto inputs = computeInputs(it->second[0]);
        auto first = _inputs[inputs->first[0]];
        auto second = _inputs[inputs->first[1]];

        if (it == _pins.rbegin())
            third = _inputs[inputs->first[2]];
        auto res = nts::component::Gate4008::compute(first, second, third);

        output = res.first;
        third = res.second;
        _outputs[it->second[0]] = output;
        if (it->second[0] == pin) {
            return output;
        }
    }
    if (pin == 14) {
        _outputs[pin] = third;
        return third;
    }
    return output;
}

std::pair<nts::Tristate, nts::Tristate> nts::component::Gate4008::compute(nts::Tristate a, nts::Tristate b, nts::Tristate c)
{
    nts::Tristate output = nts::UNDEFINED;
    nts::Tristate carry = nts::FALSE;
    nts::Tristate tempXor = nts::UNDEFINED;
    nts::Tristate tempAnd = nts::UNDEFINED;
    nts::Tristate tempAnd2 = nts::UNDEFINED;

    tempXor = nts::component::Xor::compute(a, b);
    output = nts::component::Xor::compute(tempXor, c);
    tempAnd = nts::component::And::compute(a, b);
    tempAnd2 = nts::component::And::compute(tempXor, c);
    carry = nts::component::Or::compute(tempAnd, tempAnd2);
    return std::make_pair(output, carry);
}
