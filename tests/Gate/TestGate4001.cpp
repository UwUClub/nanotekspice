//
// Created by beafowl on 16/02/23.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"

Test(4001, 4001_1, .init = cr_redirect_stdout) {
    int ac = 2;
    char *av[2] = {(char *) "./nanotekspice", (char *) "tests/nts_single/4001.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=1" << std::endl;
    f_cin << "in_3=1" << std::endl;
    f_cin << "in_4=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "  in_3: U\n"
                            "  in_4: U\n"
                            "output(s):\n"
                            "  out_1: U\n"
                            "> > > > > tick: 0\n"
                            "input(s):\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "  in_3: U\n"
                            "  in_4: U\n"
                            "output(s):\n"
                            "  out_1: U\n"
                            "> > > > tick: 1\n"
                            "input(s):\n"
                            "  in_1: 1\n"
                            "  in_2: 1\n"
                            "  in_3: 1\n"
                            "  in_4: 1\n"
                            "output(s):\n"
                            "  out_1: 0\n"
                            "> ");
}