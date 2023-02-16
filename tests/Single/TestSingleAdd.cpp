//
// Created by Beafowl on 16/02/23.
//

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Parser.hpp"
#include "Error.hpp"

Test(Add, Add, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/add.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=1" << std::endl;
    f_cin << "c_in=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > > > tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  c_in: 1\n"
                            "  in_1: 1\n"
                            "  in_2: 1\n"
                            "output(s):\n"
                            "  c_out: 1\n"
                            "  out_1: 1\n"
                            "> ");
}

Test(Add, Add2, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/add.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=0" << std::endl;
    f_cin << "c_in=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > > > tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  c_in: 1\n"
                            "  in_1: 1\n"
                            "  in_2: 0\n"
                            "output(s):\n"
                            "  c_out: 0\n"
                            "  out_1: 1\n"
                            "> ");
}

Test(Add, Add3, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/add.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=0" << std::endl;
    f_cin << "in_2=0" << std::endl;
    f_cin << "c_in=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > > > tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  c_in: 1\n"
                            "  in_1: 0\n"
                            "  in_2: 0\n"
                            "output(s):\n"
                            "  c_out: 1\n"
                            "  out_1: 0\n"
                            "> ");
}

Test(Add, Add4, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/nts_single/add.nts"};
    nts::Parser parser(ac, av);
    nts::Handler handler;
    auto &f_cin = criterion::get_redirected_cin();
    f_cin << "display" << std::endl;
    f_cin << "in_1=1" << std::endl;
    f_cin << "in_2=1" << std::endl;
    f_cin << "c_in=1" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "simulate" << std::endl;
    f_cin << "display" << std::endl;
    f_cin << "exit" << std::endl;
    f_cin.close();

    parser.getComponents(handler);
    handler.runLoop();
    cr_assert_stdout_eq_str("> tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > > > tick: 0\n"
                            "input(s):\n"
                            "  c_in: U\n"
                            "  in_1: U\n"
                            "  in_2: U\n"
                            "output(s):\n"
                            "  c_out: U\n"
                            "  out_1: U\n"
                            "> > tick: 1\n"
                            "input(s):\n"
                            "  c_in: 1\n"
                            "  in_1: 1\n"
                            "  in_2: 1\n"
                            "output(s):\n"
                            "  c_out: 1\n"
                            "  out_1: 1\n"
                            "> ");
}
