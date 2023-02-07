/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts
{
    namespace component
    {
        class Input : public nts::AComponent {
            public:
                Input(const std::string &name, std::vector<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> pins);
                ~Input();

            protected:
            private:
};
    } // namespace component
} // namespace nts

#endif /* !INPUT_HPP_ */
