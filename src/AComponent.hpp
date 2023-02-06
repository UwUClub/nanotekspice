/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <map>
#include <vector>
#include "IComponent.hpp"

namespace nts
{
    class AComponent : public IComponent
    {
        public:
            AComponent(std::string const &name, std::vector<std::size_t> nbPinsIn, std::vector<std::size_t> nbPinsOut);
            ~AComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;

            int getNbPinsIn() const override;
            int getNbPinsOut() const override;
            bool isInput(std::size_t pin) const override;
            bool isOutput(std::size_t pin) const override;
            const std::string &getName() const override;
        protected:
            std::map<std::size_t, nts::Tristate> _outputs;
            std::map<std::size_t, nts::Tristate> _inputs;
            const std::string _name;
    };
} // namespace nts


#endif /* !ACOMPONENT_HPP_ */
