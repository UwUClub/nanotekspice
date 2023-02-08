/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AShell
*/

#ifndef ASHELL_HPP_
#define ASHELL_HPP_

#include "AComponent.hpp"

namespace nts
{
    class AShell : public nts::AComponent {
        public:
            AShell(const std::string &name, const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>& pins) : nts::AComponent(name, pins)
            {
                for (auto &pin : pins)
                    for (auto &output : pin.second)
                        _outputs[output] = nts::UNDEFINED;
            }
            void setOutput(nts::Tristate state) { for (auto &output : _outputs) output.second = state; }
    };

} // namespace nts

#endif /* !ASHELL_HPP_ */
