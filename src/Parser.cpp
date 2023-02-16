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
#include <sstream>
#include "Handler.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "Error.hpp"
#include "AComponent.hpp"

nts::Parser::Parser(int ac, char **av)
{
    std::string argument = av[1];
    if (argument.find(".nts") != std::string::npos)
        _file.open(argument.c_str());
    else
        throw (nts::Error("Invalid file extension"));
    if (!_file.is_open())
        throw (nts::Error("Invalid file"));
}

nts::Parser::~Parser()
{
    _file.close();
}

void nts::Parser::getComponents(nts::Handler &handler)
{
    std::string line;
    bool bool_chipset = false;
    bool bool_links = false;
    std::pair<std::string, std::string> pair;
    std::string tmp;

    while (std::getline(_file, line)) {
        if (line.find("#") != std::string::npos)
            continue;
        pair = parseChipset(line);
        if (pair.first.empty())
            continue;
        if (pair.first == ".chipsets:") {
            bool_chipset = true;
            continue;
        }
        if (pair.first == ".links:") {
            bool_chipset = false;
            bool_links = true;
            continue;
        }
        if (bool_chipset) {
            _compLists[pair.second] = pair.first;
            handler.addComponent(pair.second, Factory::createComponent(pair.first));
        }
        if (bool_links)
            createLink(handler, line);
    }
}

std::pair<std::string, std::string> nts::Parser::parseChipset(const std::string &line)
{
    std::pair<std::string, std::string> pair;
    std::istringstream iss(line);

    iss >> pair.first;
    iss >> pair.second;
    return pair;
}

link_t nts::Parser::parseLinks(const std::string& line)
{
    std::istringstream iss(line);
    std::string firstComp;
    std::string secondComp;
    link_t link;

    iss >> firstComp;
    iss >> secondComp;
    if (firstComp.find(":") == std::string::npos || secondComp.find(":") == std::string::npos)
        throw (nts::Error("Invalid link"));
    link.first.first = firstComp.substr(0, firstComp.find(":"));
    link.first.second = firstComp.substr(firstComp.find(":") + 1, firstComp.size());
    link.second.first = secondComp.substr(0, secondComp.find(":"));
    link.second.second = secondComp.substr(secondComp.find(":") + 1, secondComp.size());
    return link;
}

void nts::Parser::createLink(nts::Handler &handler, const std::string &line)
{
    link_t link = parseLinks(line);
    IComponent *firstComp = handler.getComponent(link.first.first);
    IComponent *secondComp = handler.getComponent(link.second.first);
    outputs_t output;

    if (firstComp == nullptr || secondComp == nullptr)
        throw (nts::Error("Invalid link"));
    output = firstComp->getOutputs();
    if (output.find(stoi(link.first.second)) != output.cend()) {
        firstComp->setLink(stoi(link.first.second), *secondComp, stoi(link.second.second));
        return;
    }
    secondComp->setLink(stoi(link.second.second), *firstComp, stoi(link.first.second));
}
