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
        std::cout << "Test passed" << std::endl;
    }
    catch (nts::Error &e) {
        std::cout << e.what() << std::endl;
        cr_assert_str_eq(e.what(), "Invalid file extension (Parser.cpp line 24)");
    }
}
