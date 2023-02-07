#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>

namespace nts {
    class Parser {
    public:
        Parser(int, char **);

        ~Parser();

        std::vector<std::string> getChipsets();

        std::vector<std::string> getLinks();

        void parseChipsets();

        void parseLinks();

    private:
        std::ifstream _file;
    };
}


#endif //NANOTEKSPICE_PARSER_HPP
