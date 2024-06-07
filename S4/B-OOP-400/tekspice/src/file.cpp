/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** file
*/

#include "../include/nanotekspice.hpp"

nts::Tristate converterTriState(std::string str) {
    if (str == "1")
        return nts::True;
    else if (str == "0")
        return nts::False;
    else
        return nts::Undefined;
}

int mainActionNTS(nts::Circuit *mainCircuit) {
    if (isatty(0)) {
        std::cout << "> ";
        std::string line;
        bool looping = true;
        while (looping && std::getline(std::cin, line)) {
            if (line == "simulate")
                mainCircuit->allSimulate();
            else if (line == "display")
                mainCircuit->displayAll();
            else if (line == "loop")
                mainCircuit->loop();
            else if (line.find("=") != std::string::npos) {
                std::istringstream iss(line);
                std::string parserLeft;
                std::string parserRight;
                if (std::getline(iss, parserLeft, '=') && std::getline(iss, parserRight)) {
                    mainCircuit->changeInput(parserLeft, converterTriState(parserRight));
                }
            } else if (line == "exit") {
                looping = false;
            } else {
                std::cerr << "Invalide input" << std::endl;
            }
            if (line != "exit")
                std::cout << "> ";
        }
    } else {
        std::string line;
        bool looping = true;
        std::cout << "> ";
        while (std::getline(std::cin, line) && looping) {
            if (line == "simulate")
                mainCircuit->allSimulate();
            else if (line == "display")
                mainCircuit->displayAll();
            else if (line == "loop")
                mainCircuit->loop();
            else if (line.find("=") != std::string::npos) {
                std::istringstream iss(line);
                std::string parserLeft;
                std::string parserRight;
                if (std::getline(iss, parserLeft, '=') && std::getline(iss, parserRight)) {
                    mainCircuit->changeInput(parserLeft, converterTriState(parserRight));
                }
            } else if (line == "exit") {
                looping = false;
            } else {
                std::cerr << "Invalide input" << std::endl;
            }
            std::cout << "> ";
        }
    }
    return 0;
}
