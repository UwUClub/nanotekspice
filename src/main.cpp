/*
** EPITECH PROJECT, 2023
** uwunano
** File description:
** main.cpp
*/

#include <algorithm>
#include "Parser.hpp"
#include "Handler.hpp"

int main(int ac, char **av)
{
    nts::Parser parser(ac, av);

    parser.getComponents();
    parser.createChipsets();
    parser.createLinks();
    nts::Handler();
}