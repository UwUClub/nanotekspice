/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** main.cpp
*/

#include <algorithm>
#include "Parser.hpp"
#include "Error.hpp"
#include "Handler.hpp"
#include "Circuit.hpp"

int main(int ac, char **av) {
    if (ac == 1)
        return 84;
    try {
        nts::Parser parser(ac, av);
        parser.getComponents();
        parser.createChipsets();
        parser.createLinks();
        nts::Handler::runLoop();
    } catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
        delete nts::Circuit::getInstance();
        return 84;
    }
    delete nts::Circuit::getInstance();
    return 0;
}
