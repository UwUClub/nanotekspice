/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** main.cpp
*/

#include <iostream>
#include "Factory.hpp"
#include "Error.hpp"
#include "Graph.hpp"

int main()
{
    nts::IComponent *And = nts::Factory::createComponent(nts::CompType::AND, "and");
    nts::IComponent *True = nts::Factory::createComponent(nts::CompType::TRUE, "true");
    nts::IComponent *False = nts::Factory::createComponent(nts::CompType::FALSE, "false");

    nts::Graph *graph = nts::Graph::getInstance();

    try {
        graph->addComponent(*And);
        graph->addComponent(*True);
        graph->addComponent(*False);
        True->setLink(1, *And, 1);
        False->setLink(1, *And, 2);
        std::cout << And->compute(3) << std::endl;
    } catch (const nts::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
