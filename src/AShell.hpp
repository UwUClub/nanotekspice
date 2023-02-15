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
            AShell();
            void setOutput(nts::Tristate state);

        protected:
            enum class State { UPTODATE, TOUPDATE };
            nts::Tristate _currVal;
            nts::Tristate _nextVal;
            State _state;

        private:
    };

} // namespace nts

#endif /* !ASHELL_HPP_ */
