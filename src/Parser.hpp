#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "Handler.hpp"

typedef std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string>> link_t;

namespace nts {
    class Parser {
    public:
        Parser(int, char **);
        ~Parser();
        void getComponents(nts::Handler &handler);
        void createLink(nts::Handler &handler, const std::string &line);
    private:
        std::pair<std::string, std::string> parseChipset(const std::string &str);
        link_t parseLinks(const std::string&);

        std::ifstream _file;
    };
}


#endif //NANOTEKSPICE_PARSER_HPP
