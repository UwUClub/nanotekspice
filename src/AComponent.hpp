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

typedef std::map<std::size_t, std::pair<nts::IComponent *, std::size_t>> inputs_t;
typedef std::map<std::size_t, std::vector<nts::IComponent *>> outputs_t;

namespace nts
{
    class AComponent : public IComponent
    {
        public:
            AComponent();
            ~AComponent();

            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

            void setInput(std::size_t pin, IComponent *other, std::size_t otherPin) override;
            inputs_t getInputs() const override;
            outputs_t getOutputs() const override;
            const std::string &getType() const override;
        protected:
            outputs_t _outputs;
            inputs_t _inputs;
            std::string _type;
    };
} // namespace nts


#endif /* !ACOMPONENT_HPP_ */
