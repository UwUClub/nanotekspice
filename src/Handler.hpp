//
// Created by Beafowl on 2/9/23.
//

#ifndef NANOTEKSPICE_HANDLER_HPP
#define NANOTEKSPICE_HANDLER_HPP

#include <iostream>
#include <map>
#include "IComponent.hpp"

namespace nts {
    class Handler final {
    public:
        Handler();
        ~Handler();
        void runLoop();
        void addComponent(const std::string &name, IComponent *component);
        IComponent *getComponent(const std::string &name);
        const std::string &getComponentName(IComponent *component);
    private:
        void setOutput(const std::string &name, nts::Tristate state);
        void handleOutput(std::string &name, std::string &state, const std::string &line);
        void simulate(size_t tick);
        void loop();
        void display() const;
        std::map<std::string, IComponent *> _components;
        std::size_t _ticks;
    };
}

#endif //NANOTEKSPICE_HANDLER_HPP
