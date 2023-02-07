/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser.cpp
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include "Parser.hpp"
#include "Factory.hpp"
#include "Graph.hpp"
#include "Error.hpp"

nts::Parser::Parser(int ac, char **av)
{
    std::string argument = av[1];
    if (argument.find(".nts") != std::string::npos)
        _file.open(argument.c_str());
    else
        throw (nts::Error("Invalid file extension (Parser.cpp line 24)"));
    if (!_file.is_open())
        throw (nts::Error("Invalid file (Parser.cpp line 26)"));
}

nts::Parser::~Parser()
{
    _file.close();
}

std::vector<std::string> nts::Parser::getChipsets() {
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

std::vector<std::string> nts::Parser::getLinks() {
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

void nts::Parser::parseChipsets()
{
    std::vector<std::string> chipset = getChipsets();
    std::string split = {};
    std::string name = {};
    Graph *graph = Graph::getInstance();
    IComponent *component = nullptr;
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
        name = i.substr(i.find(' ') + 1, i.find('\n'));
        if (chipsets.find(split) != chipsets.end()) {
            component = nts::Factory::createComponent(chipsets[split], name);
            graph->addComponent(*component);
        }
        else
            throw (nts::Error("Invalid chipset (Parser.cpp, line 108)"));
    }
}

void nts::Parser::parseLinks() {
    std::string split_input = {};
    std::string split_output = {};
    std::string split_pin_input = {};
    std::string split_pin_output = {};
    std::string name_input = {};
    std::string name_output = {};
    std::vector<std::string> links = getLinks();
    unsigned int pin_in= 0;
    unsigned int pin_out = 0;
    nts::IComponent *component = nullptr;
    nts::IComponent *component2 = nullptr;
    Graph *graph = Graph::getInstance();

    for (const auto & i : links) {
        if (i == ".chipsets:" || i == ".links:")
            continue;
        split_input = i.substr(0, i.find(' '));
        split_output = i.substr(i.find(' ') + 1, i.find('\n'));
        split_pin_input = split_input.substr(split_input.find(':') + 1, split_input.find('\n'));
        split_pin_output = split_output.substr(split_output.find(':') + 1, split_output.find('\n'));
        name_input = split_input.substr(0, split_input.find(':'));
        name_output = split_output.substr(0, split_output.find(':'));
        pin_in = std::stoi(split_pin_input);
        pin_out = std::stoi(split_pin_output);
        component = graph->getCompByName(name_input);
        component2 = graph->getCompByName(name_output);
        if (component == nullptr || component2 == nullptr)
            throw (nts::Error("Invalid link (Parser.cpp, line 140)"));
        try {
            component->setLink(pin_in, *component2, pin_out);
        }
        catch (Error &e) {
            throw (nts::Error("Invalid link (Parser.cpp, line 143)"));
        }
    }
}
