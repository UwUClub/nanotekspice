/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** And.cpp
*/

#include <algorithm>
#include "And.hpp"
#include "Graph.hpp"
#include "Error.hpp"

nts::component::And::And(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins)
    : nts::AComponent(name, pins)
{
}

nts::Tristate nts::component::And::compute(std::size_t pin)
{
    Graph *graph = Graph::getInstance();
    nts::Tristate output = nts::TRUE;

    auto it = std::find_if(_pins.begin(), _pins.end(), [pin](auto &pair) {
        return std::find(pair.second.begin(), pair.second.end(), pin) != pair.second.end();
    });

    if (it == _pins.end())
        throw Error("Pin " + std::to_string(pin) + " is not an output");
    for (auto &input : it->first) {
        _inputs[input] = graph->compute(*this, input);
    }
    // access the two inputs at the same time
        for (auto &input : it->first) {
            if (_inputs[input] == nts::FALSE) {
                output = nts::FALSE;
                break;
            }
            else if (_inputs[input] == nts::UNDEFINED)
                output = nts::UNDEFINED;
        }
    _outputs[pin] = output;
    return output;
}
