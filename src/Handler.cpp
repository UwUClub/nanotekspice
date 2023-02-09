//
// Created by Beafowl on 2/9/23.
//

#include "Circuit.hpp"
#include "Handler.hpp"
#include <iostream>


nts::Handler::Handler()
{
    Circuit *Circuit = Circuit::getInstance();
    std::string line;
    int i = 0;
    std::string name;
    std::string state;

    while (std::cin >> line) {
        if (line == "exit")
            break;
        else if (line == "simulate")
            Circuit->simulate(i);
        else if (line == "display")
            Circuit->display();
        else if (line == "loop") {
            while (1) {
                Circuit->simulate(i);
                Circuit->display();
                i++;
            }
        }
        if (line.find("=") != std::string::npos) {
            name = line.substr(0, line.find('='));
            state = line.substr(line.find('=') + 1, line.size());
            Circuit->setOutput(name, state == "1" ? nts::TRUE : nts::FALSE);
        }
    }
}

nts::Handler::~Handler()
{
}
