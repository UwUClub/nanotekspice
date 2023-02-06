#include <iostream>
#include "parser.hpp"

int main(int ac, char **av) {
     parser p(ac, av);
     p.parseChipsets();
     p.parseLinks();
}
