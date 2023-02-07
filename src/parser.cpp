/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser.cpp
*/

#include "parser.hpp"
#include "Factory.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

Parser::Parser(int ac, char **av)
{
    if (ac != 2) {
        std::cout << "Usage: ./nanotekspice file.nts" << std::endl;
        exit(84);
    }
    std::string argument = av[1];
    if (argument.find(".nts") != std::string::npos)
        _file.open(argument.c_str());
    else {
        std::cout << "Invalid file" << std::endl;
        exit(84);
    }
    if (!_file.is_open()) {
        std::cout << "File failed to open" << std::endl;
        exit(84);
    }
}

Parser::~Parser()
{
    _file.close();
}

std::vector<std::string> Parser::getChipsets() {
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

std::vector<std::string> Parser::getLinks() {
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

void Parser::parseChipsets()
{
    std::vector<std::string> chipset = getChipsets();
    std::string split = {};
    std::unordered_map<std::string, nts::CompType> chipsets = {
            {"and", nts::CompType::AND},
            {"or", nts::CompType::OR},
            {"xor", nts::CompType::XOR},
            {"nand", nts::CompType::NAND},
            {"nor", nts::CompType::NOR},
            {"not", nts::CompType::NOT},
            {"input", nts::CompType::INPUT},
            {"output", nts::CompType::OUTPUT},
            {"clock", nts::CompType::CLOCK},
            {"true", nts::CompType::TRUE},
            {"false", nts::CompType::FALSE},
            {"2716", nts::CompType::ROM}
    };

    for (const auto & i : chipset) {
        if (i == ".chipsets:" || i == ".links:")
            continue;
        split = i.substr(0, i.find(' '));
        if (chipsets.find(split) != chipsets.end())
            nts::Factory::createComponent(chipsets[split]);
        else {
            std::cout << "Invalid chipset" << std::endl;
            exit(84);
        }
    }
}

void Parser::parseLinks() {
    std::string split_input = {};
    std::string split_output = {};
    std::vector<std::string> links = getLinks();

    for (const auto & i : links) {
        if (i == ".chipsets:" || i == ".links:")
            continue;
        split_input = i.substr(0, i.find(' '));
        split_output = i.substr(i.find(' ') + 1, i.find('\n'));
        std::cout << split_input << std::endl;
        std::cout << split_output << std::endl;
    }
}
