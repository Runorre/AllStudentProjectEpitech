/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include "../../include/nanotekspice.hpp"

namespace nts {
    class Factory {
        public:
            static std::map<std::string, nts::IComponent* (*) (std::string)> getFactoryMap();
            static nts::IComponent *factoryCreator(std::string type, std::string name);

            static nts::IComponent *createInput(std::string name);
            static nts::IComponent *createOutput(std::string name);
            static nts::IComponent *createTrue(std::string name);
            static nts::IComponent *createFalse(std::string name);
            static nts::IComponent *createClock(std::string name);

            static nts::IComponent *createOr(std::string name);
            static nts::IComponent *createAnd(std::string name);
            static nts::IComponent *createNot(std::string name);
            static nts::IComponent *createNand(std::string name);
            static nts::IComponent *createNor(std::string name);
            static nts::IComponent *createXor(std::string name);
            static nts::IComponent *createNxor(std::string name);
            
            static nts::IComponent *create4001(std::string name);
            static nts::IComponent *create4011(std::string name);
            static nts::IComponent *create4030(std::string name);
            static nts::IComponent *create4069(std::string name);
            static nts::IComponent *create4071(std::string name);
            static nts::IComponent *create4081(std::string name);

            static nts::IComponent *create4008(std::string name);
            static nts::IComponent *createLogger(std::string name);
            static nts::IComponent *create4013(std::string name);
            static nts::IComponent *create4040(std::string name);

    };
}

#endif /* !FACTORY_HPP_ */
