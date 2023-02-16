/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** AComposedComponent
*/

#include "AComposedComponent.hpp"

nts::AComposedComponent::AComposedComponent() : nts::AComponent()
{
    _subComponents = std::vector<nts::IComponent *>();
}

nts::AComposedComponent::~AComposedComponent()
{
    for (auto &subComponent : _subComponents) {
        delete subComponent;
    }
}
