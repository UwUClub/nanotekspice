/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** main.cpp
*/

#include <iostream>
#include "Error.hpp"
#include "Circuit.hpp"
#include "Parser.hpp"

int main(int ac, char **av)
{
    try {
        nts::Parser p(ac, av);
        p.getComponents();
        p.createChipsets();
        p.createLinks();
    }
    catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}