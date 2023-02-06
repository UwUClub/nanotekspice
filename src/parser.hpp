#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <iostream>
#include <fstream>
#include <vector>

class parser {
public:
    parser(int, char **);
    ~parser();
    std::vector<std::string> parseChipsets();
    std::vector<std::string> parseLinks();
    void open_file(std::string argv);
private:
    std::ifstream _file;
};


#endif //NANOTEKSPICE_PARSER_HPP
