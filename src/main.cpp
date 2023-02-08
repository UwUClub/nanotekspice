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
    nts::IComponent *And = nts::Factory::createComponent(nts::CompType::AND, "and");
    nts::IComponent *Andz = nts::Factory::createComponent(nts::CompType::AND, "and1");
    nts::component::Clock *In = dynamic_cast<nts::component::Clock *>(nts::Factory::createComponent(nts::CompType::CLOCK, "input"));
    nts::IComponent *Truez = nts::Factory::createComponent(nts::CompType::TRUE, "true1");
    nts::IComponent *False = nts::Factory::createComponent(nts::CompType::TRUE, "false");
    nts::IComponent *Out = nts::Factory::createComponent(nts::CompType::OUTPUT, "output");

    nts::Circuit *Circuit = nts::Circuit::getInstance();

    try {
        Circuit->addComponent(*And);
        Circuit->addComponent(*In);
        Circuit->addComponent(*False);
        Circuit->addComponent(*Andz);
        Circuit->addComponent(*Truez);
        Circuit->addComponent(*Out);
        In->setLink(1, *And, 1);
        False->setLink(1, *And, 2);
        Truez->setLink(1, *Andz, 1);
        Andz->setLink(2, *And, 3);
        Out->setLink(1, *Andz, 3);
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