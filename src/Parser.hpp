#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include "Handler.hpp"

namespace nts {
    class Parser {
    public:
        Parser(int, char **);
        ~Parser();
        void getComponents();
        void createChipsets();
        void createLinks(nts::Handler handler);
        void parseLinks(const std::string&, bool);
    private:
        std::ifstream _file;
        std::vector<std::string> _chipsets_type;
        std::vector<std::string> _chipsets_name;
        std::vector<std::string> _linksType1;
        std::vector<std::string> _linksPin1;
        std::vector<std::string> _linksType2;
        std::vector<std::string> _linksPin2;
    };
}


#endif //NANOTEKSPICE_PARSER_HPP
