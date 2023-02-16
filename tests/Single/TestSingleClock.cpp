//
// Created by beafowl on 16/02/23.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"

Test(Clock, Clock1, .init = cr_redirect_stdout) {
    int ac = 2;
    char *av[2] = {(char *) "./nanotekspice", (char *) "tests/nts_single/clock.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "cl=0" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  cl: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 0\n"
                            "input(s):\n"
                            "  cl: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  cl: 0\n"
                            "output(s):\n"
                            "  out: 0\n"
                            "> > > tick: 3\n"
                            "input(s):\n"
                            "  cl: 0\n"
                            "output(s):\n"
                            "  out: 0\n"
                            "> ");
}

Test(Clock, Clock2, .init = cr_redirect_stdout) {
    int ac = 2;
    char *av[2] = {(char *) "./nanotekspice", (char *) "tests/nts_single/clock.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "cl=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  cl: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 0\n"
                            "input(s):\n"
                            "  cl: U\n"
                            "output(s):\n"
                            "  out: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  cl: 1\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> > > tick: 3\n"
                            "input(s):\n"
                            "  cl: 1\n"
                            "output(s):\n"
                            "  out: 1\n"
                            "> ");
}