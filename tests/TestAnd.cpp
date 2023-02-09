/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** TestAnd.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "And.hpp"
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
        cr_assert_str_eq(e.what(), "Invalid file extension (Parser.cpp line 24)");
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
        cr_assert_str_eq(e.what(), "Invalid file (Parser.cpp line 26)");
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
        cr_assert_str_eq(e.what(), "No chipsets in file (Parser.cpp line 42)");
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
        cr_assert_str_eq(e.what(), "No links in file (Parser.cpp line 65)");
        std::cout << "Test passed" << std::endl;
    }
    catch (nts::Error &e) {
        std::cout << e.what() << std::endl;
        cr_assert_eq(e.what(), "Invalid file extension (Parser.cpp line 24)");
    }
}
