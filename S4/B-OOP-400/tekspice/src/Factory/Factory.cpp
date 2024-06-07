/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** Factory
*/

#include "../../include/nanotekspice.hpp"

std::map<std::string, nts::IComponent* (*) (std::string)> factorymap = {
    {"input", nts::Factory::createInput},
    {"output", nts::Factory::createOutput},
    {"true", nts::Factory::createTrue},
    {"false", nts::Factory::createFalse},
    {"clock", nts::Factory::createClock},

    {"or", nts::Factory::createOr},
    {"and", nts::Factory::createAnd},
    {"xor", nts::Factory::createXor},
    {"not", nts::Factory::createNot},
    {"nand", nts::Factory::createNand},
    {"nor", nts::Factory::createNor},
    {"nxor", nts::Factory::createXor},

    {"4001", nts::Factory::create4001},
    {"4011", nts::Factory::create4011},
    {"4030", nts::Factory::create4030},
    {"4069", nts::Factory::create4069},
    {"4071", nts::Factory::create4071},
    {"4081", nts::Factory::create4081},

    {"4008", nts::Factory::create4008},
    {"logger", nts::Factory::createLogger},
    
    {"4013", nts::Factory::create4013},
    {"4040", nts::Factory::create4040},
    // {"4017", nts::Factory::createInput},
    // {"4094", nts::Factory::createInput},
    // {"4512", nts::Factory::createInput},
    // {"4514", nts::Factory::createInput},
    // {"4801", nts::Factory::createInput},
    // {"2716", nts::Factory::createInput},
};

std::map<std::string, nts::IComponent* (*) (std::string)> nts::Factory::getFactoryMap() {
    return factorymap;
}

nts::IComponent *nts::Factory::factoryCreator(std::string type, std::string name) {
    return factorymap[type](name);
}

nts::IComponent *nts::Factory::createInput(std::string name) {
    return new InputComponent(name);
}

nts::IComponent *nts::Factory::createOr(std::string name) {
    return new OrComponent(name);
}

nts::IComponent *nts::Factory::createAnd(std::string name) {
    return new AndComponent(name);
}

nts::IComponent *nts::Factory::createNot(std::string name) {
    return new NotComponent(name);
}

nts::IComponent *nts::Factory::createNand(std::string name) {
    return new NandComponent(name);
}

nts::IComponent *nts::Factory::createNor(std::string name) {
    return new NorComponent(name);
}

nts::IComponent *nts::Factory::createXor(std::string name) {
    return new XorComponent(name);
}

nts::IComponent *nts::Factory::createNxor(std::string name) {
    return new NxorComponent(name);
}

nts::IComponent *nts::Factory::createTrue(std::string name) {
    return new TrueComponent(name);
}

nts::IComponent *nts::Factory::createFalse(std::string name) {
    return new FalseComponent(name);
}

nts::IComponent *nts::Factory::createOutput(std::string name) {
    return new OutputComponent(name);
}

nts::IComponent *nts::Factory::createClock(std::string name) {
    return new ClockComponent(name);
}

nts::IComponent *nts::Factory::create4001(std::string name) {
    return new quatreMilleUnComponent(name);
}

nts::IComponent *nts::Factory::create4011(std::string name) {
    return new quatreMilleOnzeComponent(name);
}

nts::IComponent *nts::Factory::create4030(std::string name) {
    return new quatreMilleTrenteComponent(name);
}

nts::IComponent *nts::Factory::create4069(std::string name) {
    return new quatreMilleSoixanteNeufComponent(name);
}

nts::IComponent *nts::Factory::create4071(std::string name) {
    return new quatreMilleSoixanteOnzeComponent(name);
}

nts::IComponent *nts::Factory::create4081(std::string name) {
    return new quatreMilleQutreVingtUnComponent(name);
}

nts::IComponent *nts::Factory::create4008(std::string name) {
    return new quatreMilleHuitComponent(name);
}

nts::IComponent *nts::Factory::createLogger(std::string name) {
    return new loggerComponent(name);
}

nts::IComponent *nts::Factory::create4013(std::string name) {
    return new quatreMilleTreizeComponent(name);
}

nts::IComponent *nts::Factory::create4040(std::string name) {
    return new quatreMilleQuaranteComponent(name);
}