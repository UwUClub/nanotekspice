//
// Created by Beafowl on 2/9/23.
//

#ifndef NANOTEKSPICE_HANDLER_HPP
#define NANOTEKSPICE_HANDLER_HPP

#include <iostream>
#include <map>
#include "IComponent.hpp"

namespace nts {
    class Handler {
    public:
        Handler();
        ~Handler();
        void runLoop(nts::Handler handler);
        void addComponent(const std::string &name, IComponent *component);
        IComponent *getComponent(const std::string &name);
    private:
        std::map<std::string, IComponent *> _components;
        std::size_t _ticks;
    };
}

#endif //NANOTEKSPICE_HANDLER_HPP
