/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** main.cpp
*/

#include <iostream>
#include <algorithm>
#include "Factory.hpp"
#include "Error.hpp"
#include "Clock.hpp"
#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    nts::IComponent *Or = nts::Factory::createComponent(nts::CompType::OR, "or");
    nts::IComponent *Or2 = nts::Factory::createComponent(nts::CompType::OR, "or2");
    nts::component::Clock *In = dynamic_cast<nts::component::Clock *>(nts::Factory::createComponent(nts::CompType::CLOCK, "input"));
    nts::IComponent *True = nts::Factory::createComponent(nts::CompType::FALSE, "true1");
    nts::IComponent *False = nts::Factory::createComponent(nts::CompType::FALSE, "false");
    nts::IComponent *Out = nts::Factory::createComponent(nts::CompType::OUTPUT, "output");

    nts::Circuit *Circuit = nts::Circuit::getInstance();

    try {
        Circuit->addComponent(*Or);
        Circuit->addComponent(*Or2);
        Circuit->addComponent(*False);
        Circuit->addComponent(*Out);
        Circuit->addComponent(*True);
        Circuit->addComponent(*In);
        True->setLink(1, *Or, 1);
        False->setLink(1, *Or, 2);
        Or->setLink(3, *Or2, 1);
        In->setLink(1, *Or2, 2);
        Out->setLink(1, *Or2, 3);
        std::cout << Out->compute() << std::endl;
        In->setOutput(nts::TRUE);
        std::cout << Out->compute() << std::endl;
        Circuit->simulate(1);
        std::cout << Out->compute() << std::endl;
    } catch (const nts::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}