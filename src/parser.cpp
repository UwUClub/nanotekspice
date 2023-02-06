/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser.cpp
*/

#include "parser.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void parser::open_file(std::string argument)
{
    _file.open(argument.c_str());
    if (!_file.is_open()) {
        std::cout << "File failed to open" << std::endl;
        exit(84);
    }
}

parser::parser(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage: ./nanotekspice file.nts" << std::endl;
        exit(84);
    }
    std::string argument = av[1];
    if (argument.find(".nts") != std::string::npos)
        open_file(argument);
    else {
        std::cout << "Invalid file" << std::endl;
        exit(84);
    }
}

parser::~parser()
{
}

std::vector<std::string> parser::parseChipsets() {
    std::string line;
    std::vector<std::string> chipset;
    bool links = false;

    _file.clear();
    _file.seekg(0, std::ios::beg);
    while (std::getline(_file, line)) {
        if (line.find(".links:") != std::string::npos)
            links = true;
        if (line.find('#') != std::string::npos)
            continue;
        if (links)
            continue;
        if (line == "\n" || line.empty())
            continue;
        chipset.push_back(line.substr(0, line.find('\n')));
    }
    return chipset;
}

std::vector<std::string> parser::parseLinks() {
    std::string line;
    std::vector<std::string> links;
    bool chipset = true;

    _file.clear();
    _file.seekg(0, std::ios::beg);
    while (std::getline(_file, line)) {
        if (line.find(".links:") != std::string::npos)
            chipset = false;
        if (line.find('#') != std::string::npos)
            continue;
        if (chipset)
            continue;
        if (line == "\n" || line.empty())
            continue;
        links.push_back(line.substr(0, line.find('\n')));
    }
    return links;
}
