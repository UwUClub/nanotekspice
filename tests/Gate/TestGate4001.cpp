//
// Created by beafowl on 16/02/23.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"

Test(nor_gate, nor_gate, .init = cr_redirect_stdout) {
    int ac = 2;
    char *av[2] = {(char *) "./nanotekspice", (char *) "tests/nts_single/4001_nor.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_01=1" << std::endl;
    f_cin << "in_02=1" << std::endl;
    f_cin << "in_05=0" << std::endl;
    f_cin << "in_06=1" << std::endl;
    f_cin << "in_08=1" << std::endl;
    f_cin << "in_09=0" << std::endl;
    f_cin << "in_12=0" << std::endl;
    f_cin << "in_13=0" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  in_01: U\n"
                            "  in_02: U\n"
                            "  in_05: U\n"
                            "  in_06: U\n"
                            "  in_08: U\n"
                            "  in_09: U\n"
                            "  in_12: U\n"
                            "  in_13: U\n"
                            "output(s):\n"
                            "  out_03: U\n"
                            "  out_04: U\n"
                            "  out_10: U\n"
                            "  out_11: U\n"
                            "> > > > > > > > > tick: 0\n"
                            "input(s):\n"
                            "  in_01: U\n"
                            "  in_02: U\n"
                            "  in_05: U\n"
                            "  in_06: U\n"
                            "  in_08: U\n"
                            "  in_09: U\n"
                            "  in_12: U\n"
                            "  in_13: U\n"
                            "output(s):\n"
                            "  out_03: U\n"
                            "  out_04: U\n"
                            "  out_10: U\n"
                            "  out_11: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  in_01: 1\n"
                            "  in_02: 1\n"
                            "  in_05: 0\n"
                            "  in_06: 1\n"
                            "  in_08: 1\n"
                            "  in_09: 0\n"
                            "  in_12: 0\n"
                            "  in_13: 0\n"
                            "output(s):\n"
                            "  out_03: 0\n"
                            "  out_04: 0\n"
                            "  out_10: 0\n"
                            "  out_11: 1\n"
                            "> ");
}