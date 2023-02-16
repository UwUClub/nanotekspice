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
    nts::Handler handler;
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

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  in: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 0\n"
                            "input(s):\n"
                            "  in: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  in: 1\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> ");
}

Test(InputOutput, InputOutput2, .init = cr_redirect_stdout)
{
    nts::Handler handler;
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

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  in: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 0\n"
                            "input(s):\n"
                            "  in: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  in: 0\n"
                            "output(s):\n"
                            "  out: 0\n"
                            "> ");
}
