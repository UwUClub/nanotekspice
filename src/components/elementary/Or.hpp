/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Or
*/

#ifndef OR_HPP_
#define OR_HPP_

#include "AComponent.hpp"

namespace nts::component
{
    class Or : public nts::AComponent {
        public:
            Or(const std::string &name,
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins =
                std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>>{std::make_pair(std::vector<std::size_t>{1, 2}, std::vector<std::size_t>{3})});

            nts::Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override {};

            static nts::Tristate compute(nts::Tristate a, nts::Tristate b);
        protected:
        private:
    };
} // namespace nts

#endif /* !OR_HPP_ */
