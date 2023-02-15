/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AComposedComponent
*/

#ifndef ACOMPOSEDCOMPONENT_HPP_
#define ACOMPOSEDCOMPONENT_HPP_

#include <vector>
#include "AComponent.hpp"
#include "Factory.hpp"

namespace nts
{
    class AComposedComponent : public nts::AComponent {
        public:
            AComposedComponent();
            ~AComposedComponent();

        protected:
            std::vector<nts::IComponent *> _subComponents;
    };
} // namespace nts

#endif /* !ACOMPOSEDCOMPONENT_HPP_ */
