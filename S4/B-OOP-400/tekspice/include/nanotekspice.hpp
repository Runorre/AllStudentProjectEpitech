/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** nanotekspice
*/

#ifndef NANOTEKSPICE_HPP_
    #define NANOTEKSPICE_HPP_
    #include "IComponent.hpp"
    
    #include "../src/Circuit/Circuit.hpp"
    
    #include "../src/Components/AComponents/AComponent.hpp"
    #include "../src/Components/InputComponent/InputComponent.hpp"
    #include "../src/Components/TrueComponent/TrueComponent.hpp"
    #include "../src/Components/FalseComponent/FalseComponent.hpp"
    #include "../src/Components/OutputComponent/OutputComponent.hpp"
    #include "../src/Components/ClockComponent/ClockComponent.hpp"
    #include "../src/Components/AndComponent/AndComponent.hpp"
    #include "../src/Components/NandComponent/NandComponent.hpp"
    #include "../src/Components/OrComponent/OrComponent.hpp"
    #include "../src/Components/NorComponent/NorComponent.hpp"
    #include "../src/Components/XorComponent/XorComponent.hpp"
    #include "../src/Components/NxorComponent/NxorComponent.hpp"
    #include "../src/Components/NotComponent/NotComponent.hpp"
    #include "../src/Components/4001Component/4001Component.hpp"
    #include "../src/Components/4071Component/4071Component.hpp"
    #include "../src/Components/4011Component/4011Component.hpp"
    #include "../src/Components/4081Component/4081Component.hpp"
    #include "../src/Components/4030Component/4030Component.hpp"
    #include "../src/Components/4069Component/4069Component.hpp"
    #include "../src/Components/4008Component/4008Component.hpp"
    #include "../src/Components/LoggerComponent/loggerComponent.hpp"
    #include "../src/Components/4013Component/4013Component.hpp"
    #include "../src/Components/4040Component/4040Component.hpp"

    #include "../src/Factory/Factory.hpp"

    #include <cstddef>
    #include <vector>
    #include <map>
    #include <ostream>
    #include <memory>
    #include <fstream>
    #include <sstream>
    #include <regex>
    #include <cstdlib>
    #include <iostream>
    #include <queue>
    #include <unistd.h>
    using namespace std;

    int parseFile(const char *filepath);
    int mainActionNTS(nts::Circuit *mainCircuit);
#endif /* !NANOTEKSPICE_HPP_ */
