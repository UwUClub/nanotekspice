#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>

class parser {
public:
    parser(int, char **);
    ~parser();
    std::vector<std::string> getChipsets();
    std::vector<std::string> getLinks();
    void parseChipsets();
private:
    std::ifstream _file;
};


#endif //NANOTEKSPICE_PARSER_HPP
