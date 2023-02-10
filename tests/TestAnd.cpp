/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** TestAnd.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"
#include "Handler.hpp"

Test(And, And, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/and.nts"};
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
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > > tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "\tgate: 1\n"
                            "\tin_1: 1\n"
                            "\tin_2: 1\n"
                            "output(s):\n"
                            "\tout: 1\n"
                            "> ");
}

Test(And, And2, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./naotekspice", (char *)"tests/nts_single/and.nts"};
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
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > > tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "\tgate: 0\n"
                            "\tin_1: 1\n"
                            "\tin_2: 0\n"
                            "output(s):\n"
                            "\tout: 0\n"
                            "> ");
}

Test(And, And3, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/and.nts"};
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
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > > tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "\tgate: 0\n"
                            "\tin_1: 0\n"
                            "\tin_2: 1\n"
                            "output(s):\n"
                            "\tout: 0\n"
                            "> ");
}

Test(And, And4, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/and.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=0" << std::endl;
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
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > > tick: 0\n"
                            "input(s):\n"
                            "\tgate: U\n"
                            "\tin_1: U\n"
                            "\tin_2: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "\tgate: 0\n"
                            "\tin_1: 0\n"
                            "\tin_2: 0\n"
                            "output(s):\n"
                            "\tout: 0\n"
                            "> ");
}
