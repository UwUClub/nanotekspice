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

    while (std::getline(_file, line)) {
        if (size_t pos = line.find("#") != std::string::npos) {
            if (pos == 0)
                continue;
            line = line.substr(0, line.find("#"));
        }
        if (line.empty())
            continue;
        pair = parseChipset(line);
        if (pair.first.empty())
            continue;
        if (pair.first == ".chipsets:") {
            bool_chipset = true;
            continue;
        }
        if (pair.first == ".links:") {
            if (!bool_chipset)
                throw (nts::Error("Invalid file"));
            bool_chipset = false;
            bool_links = true;
            continue;
        }
        if (bool_chipset) {
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
    std::size_t posFirstComp = 0;
    std::size_t posSecondComp = 0;

    iss >> firstComp;
    iss >> secondComp;
    posFirstComp = firstComp.find(":");
    posSecondComp = secondComp.find(":");
    if (posFirstComp == std::string::npos || posSecondComp == std::string::npos)
        throw (nts::Error("Invalid link"));
    link.first.first = firstComp.substr(0, posFirstComp);
    link.first.second = firstComp.substr(posFirstComp + 1, firstComp.size());
    link.second.first = secondComp.substr(0, posSecondComp);
    link.second.second = secondComp.substr(posSecondComp + 1, secondComp.size());
    return link;
}

void nts::Parser::createLink(nts::Handler &handler, const std::string &line)
{
    link_t link = parseLinks(line);
    IComponent *firstComp = handler.getComponent(link.first.first);
    IComponent *secondComp = handler.getComponent(link.second.first);
    std::size_t firstPin = stoi(link.first.second);
    std::size_t secondPin = stoi(link.second.second);
    outputs_t output;

    if (firstComp == nullptr || secondComp == nullptr)
        throw (nts::Error("Invalid link"));
    output = firstComp->getOutputs();
    if (output.find(firstPin) != output.cend()) {
        firstComp->setLink(firstPin, *secondComp, secondPin);
        return;
    }
    secondComp->setLink(secondPin, *firstComp, firstPin);
}
