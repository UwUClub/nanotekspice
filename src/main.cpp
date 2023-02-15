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

int main(int ac, char **av) {
    if (ac == 1)
        return 84;
    try {
        nts::Handler handler;
        nts::Parser parser(ac, av);
        parser.getComponents();
        parser.createChipsets();
        parser.createLinks(handler);
        handler.runLoop(handler);
    } catch (nts::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
