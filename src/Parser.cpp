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
#include "Circuit.hpp"
#include "Error.hpp"

nts::Parser::Parser(int ac, char **av)
{
    std::string argument = av[1];
    if (argument.find(".nts") != std::string::npos)
        _file.open(argument.c_str());
    else
        throw (nts::Error("Invalid file extension (Parser.cpp line 23)"));
    if (!_file.is_open())
        throw (nts::Error("Invalid file (Parser.cpp line 25)"));
}

nts::Parser::~Parser()
{
    _file.close();
}

void nts::Parser::getComponents() {
    std::string line;
    bool bool_chipset = false;
    bool bool_links = false;
    int i = 1;
    std::string tmp;

    while (_file >> line) {
        if (line.find('#') != std::string::npos) {
            std::getline(_file, tmp);
            continue;
        }
        if (line == ".chipsets:")
            bool_chipset = true;
        if (line == ".links:") {
            bool_chipset = false;
            bool_links = true;
            continue;
        }
        if (bool_chipset && i % 2 == 0)
            _chipsets_type.push_back(line);
        else if (bool_chipset && i % 1 == 0)
            _chipsets_name.push_back(line);
        if (bool_links && i % 2 == 0) {
            try {
                parseLinks(line, true);
            }
            catch (nts::Error &e) {
                throw (nts::Error(e.what()));
            }
        }
        else if (bool_links && i % 1 == 0) {
            try {
                parseLinks(line, false);
            }
            catch (nts::Error &e) {
                throw (nts::Error(e.what()));
            }
        }
        i++;
    }
    if (_chipsets_type.empty())
        throw (nts::Error("No chipset (Parser.cpp, line 75)"));
    if (_linksType1.empty())
        throw (nts::Error("No link (Parser.cpp, line 77)"));
}

void nts::Parser::parseLinks(const std::string& str, bool isInput) {
    if (str.find(':') == std::string::npos)
        throw (nts::Error("Invalid link (Parser.cpp, line 82)"));
    if (isInput) {
        _linksType1.push_back(str.substr(0, str.find(':')));
        _linksPin1.push_back(str.substr(str.find(':') + 1, str.find('\n')));
    }
    else {
        _linksType2.push_back(str.substr(0, str.find(':')));
        _linksPin2.push_back(str.substr(str.find(':') + 1, str.find('\n')));
    }
}

void nts::Parser::createChipsets() {
    Circuit *circuit = Circuit::getInstance();
    IComponent *comp = nullptr;
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
            {"2716", nts::CompType::ROM},
            {"4071", nts::CompType::GATE_4071},
            {"4001", nts::CompType::GATE_4001},
            {"4011", nts::CompType::GATE_4011},
            {"4030", nts::CompType::GATE_4030},
            {"4069", nts::CompType::GATE_4069},
            {"4081", nts::CompType::GATE_4081},
            {"4008", nts::CompType::GATE_4008},
            {"4013", nts::CompType::GATE_4013}
    };

    for (int i = 0; i < _chipsets_type.size();) {
        if (chipsets.find(_chipsets_type.back()) == chipsets.end())
            throw (nts::Error("Invalid chipset (Parser.cpp, line 119)"));
        if (chipsets.find(_chipsets_type.back()) != chipsets.end()) {
            comp = Factory::createComponent(chipsets[_chipsets_type.back()], _chipsets_name.back());
            circuit->addComponent(*comp);
            _chipsets_type.pop_back();
            _chipsets_name.pop_back();
        }
    }
}

void nts::Parser::createLinks() {
    Circuit *circuit = Circuit::getInstance();
    IComponent *comp1 = nullptr;
    IComponent *comp2 = nullptr;

    for (int i = 0; i < _linksType1.size();) {
        comp1 = circuit->getCompByName(_linksType1.back());
        comp2 = circuit->getCompByName(_linksType2.back());
        if (comp1 == nullptr || comp2 == nullptr)
            throw (nts::Error("Cannot link a not created component (Parser.cpp, line 138)"));
        comp1->setLink(std::stoi(_linksPin1.back()), *comp2, std::stoi(_linksPin2.back()));
        _linksType1.pop_back();
        _linksType2.pop_back();
        _linksPin1.pop_back();
        _linksPin2.pop_back();
    }
}
