/*
** EPITECH PROJECT, 2023
** unit_test
** File description:
** TestInputOutput.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"
#include "Handler.hpp"

Test(InputOutput, InputOutput, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/input_output.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in=1" << std::endl;
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
                            "\tin: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 0\n"
                            "input(s):\n"
                            "\tin: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "\tin: 1\n"
                            "output(s):\n"
                            "\tout: 1\n"
                            "> ");
}

Test(InputOutput, InputOutput2, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/input_output.nts"};
    nts::Parser parser(ac, av);
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in=0" << std::endl;
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
                            "\tin: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 0\n"
                            "input(s):\n"
                            "\tin: U\n"
                            "output(s):\n"
                            "\tout: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "\tin: 0\n"
                            "output(s):\n"
                            "\tout: 0\n"
                            "> ");
}
