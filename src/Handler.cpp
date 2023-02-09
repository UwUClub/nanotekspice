//
// Created by Beafowl on 2/9/23.
//

#include "Circuit.hpp"
#include "Handler.hpp"
#include "Error.hpp"
#include <iostream>


nts::Handler::Handler() = default;

nts::Handler::~Handler() = default;

void nts::Handler::runLoop()
{
    Circuit *Circuit = Circuit::getInstance();
    std::string line;
    int i = 0;
    std::string name;
    std::string state;

    std::cout << "> ";
    while (std::cin >> line) {
        if (line == "exit")
            break;
        else if (line == "simulate") {
            i++;
            Circuit->simulate(i);
        }
        else if (line == "display")
            Circuit->display();
        else if (line == "loop") {
            while (1) {
                Circuit->simulate(i);
                Circuit->display();
                i++;
            }
        }
        else if (line.find('=') != std::string::npos) {
            name = line.substr(0, line.find('='));
            state = line.substr(line.find('=') + 1, line.size());
            if (state == "0")
                Circuit->setOutput(name, nts::FALSE);
            else if (state == "1")
                Circuit->setOutput(name, nts::TRUE);
            else if (state == "U")
                Circuit->setOutput(name, nts::UNDEFINED);
            else
                std::cout << "Invalid State" << std::endl;
        } else {
            std::cout << "Invalid Command" << std::endl;
        }
        std::cout << "> ";
    }
}
