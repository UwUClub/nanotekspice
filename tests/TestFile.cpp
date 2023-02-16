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

Test(And, ErrorHandling, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/Test.circ"};
    try {
        nts::Parser p(ac, av);
    }
    catch (nts::Error &e) {
        cr_assert_str_eq(e.what(), "Invalid file extension");
    }
}

Test(And, ErrorHandling2)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/test.nts"};
    try {
        nts::Parser p(ac, av);
    }
    catch (nts::Error &e) {
        cr_assert_str_eq(e.what(), "Invalid file");
    }
}

Test(And, ErrorHandling3)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/test_no_chipsets.nts"};
    try {
        nts::Parser p(ac, av);
    }
    catch (nts::Error &e) {
        cr_assert_str_eq(e.what(), "No chipset (Parser.cpp, line 75)");
    }
}

Test(And, ErrorHandling4)
{
    int ac = 2;
    char *av[2] = {(char *)"./nanotekspice", (char *)"tests/test_no_links.nts"};
    try {
        nts::Parser p(ac, av);
    }
    catch (nts::Error &e) {
        cr_assert_str_eq(e.what(), "No link (Parser.cpp, line 77)");
        std::cout << "Test passed" << std::endl;
    }
}
