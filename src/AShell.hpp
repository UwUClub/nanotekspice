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
            AShell(const std::string &name, const std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>& pins);
            void setOutput(nts::Tristate state);

        protected:
            enum class State { UPTODATE, TOUPDATE };
            nts::Tristate _temp;
            State _state;

        private:
    };

} // namespace nts

#endif /* !ASHELL_HPP_ */
