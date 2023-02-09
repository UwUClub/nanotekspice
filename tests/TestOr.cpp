/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** TestOr.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"
#include "Handler.hpp"

Test(Or, ErrorHandling, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/or.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents();
    parser.createChipsets();
    parser.createLinks();
    nts::Handler::runLoop();
    cr_assert_stdout_eq_str("> Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > > Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > Tick: 1\n"
                            "Inputs:\n"
                            "\tin_1: 1\n"
                            "\tin_2: 1\n"
                            "Outputs:\n"
                            "\tout: 1\n"
                            "> ");
}

Test(Or, Or, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/or.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents();
    parser.createChipsets();
    parser.createLinks();
    nts::Handler::runLoop();
    cr_assert_stdout_eq_str("> Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > > Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > Tick: 1\n"
                            "Inputs:\n"
                            "\tin_1: 1\n"
                            "\tin_2: 1\n"
                            "Outputs:\n"
                            "\tout: 1\n"
                            "> ");
}

Test(Or, Or2, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/or.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=0" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents();
    parser.createChipsets();
    parser.createLinks();
    nts::Handler::runLoop();
    cr_assert_stdout_eq_str("> Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > > Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > Tick: 1\n"
                            "Inputs:\n"
                            "\tin_1: 1\n"
                            "\tin_2: 0\n"
                            "Outputs:\n"
                            "\tout: 1\n"
                            "> ");
}

Test(Or, Or3, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/or.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=0" << std::endl;
    f_cin << "in_2=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents();
    parser.createChipsets();
    parser.createLinks();
    nts::Handler::runLoop();
    cr_assert_stdout_eq_str("> Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > > Tick: 0\n"
                            "Inputs:\n"
                            "\tin_1: -1\n"
                            "\tin_2: -1\n"
                            "Outputs:\n"
                            "\tout: -1\n"
                            "> > Tick: 1\n"
                            "Inputs:\n"
                            "\tin_1: 0\n"
                            "\tin_2: 1\n"
                            "Outputs:\n"
                            "\tout: 1\n"
                            "> ");
}
