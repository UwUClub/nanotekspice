/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** main.cpp
*/

#include <iostream>
#include "Factory.hpp"
#include "Error.hpp"
#include "Circuit.hpp"

int main()
{
    nts::IComponent *And = nts::Factory::createComponent(nts::CompType::AND, "and");
    nts::IComponent *Andz = nts::Factory::createComponent(nts::CompType::AND, "and1");
    nts::IComponent *True = nts::Factory::createComponent(nts::CompType::TRUE, "true");
    nts::IComponent *Truez = nts::Factory::createComponent(nts::CompType::TRUE, "true1");
    nts::IComponent *False = nts::Factory::createComponent(nts::CompType::TRUE, "false");

    nts::Circuit *Circuit = nts::Circuit::getInstance();

    try {
        Circuit->addComponent(*And);
        Circuit->addComponent(*True);
        Circuit->addComponent(*False);
        Circuit->addComponent(*Andz);
        Circuit->addComponent(*Truez);
        True->setLink(1, *And, 1);
        False->setLink(1, *And, 2);
        Truez->setLink(1, *Andz, 1);
        Andz->setLink(2, *And, 3);
        std::cout << Andz->compute(3) << std::endl;
    } catch (const nts::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}