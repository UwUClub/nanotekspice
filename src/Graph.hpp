/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** Graph
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <map>
#include <vector>
#include <string>
#include "IComponent.hpp"

namespace nts
{
    class Graph final {
        public:
            static Graph *getInstance();
            ~Graph();
            void setLink(nts::IComponent &component, std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void addComponent(nts::IComponent &component);

        private:
            Graph() = default;
            Graph(const Graph &) = delete;

            enum class Type {
                INPUT,
                OUTPUT
            };

            std::map<nts::IComponent *, std::map<Type, std::vector<std::pair<size_t, nts::IComponent *>>>> _components;
    };
} // namespace nts
#endif /* !GRAPH_HPP_ */
