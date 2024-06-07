/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_
#include "../../include/nanotekspice.hpp"
#include <vector>

namespace nts {
    class Circuit {
        public:
            Circuit(std::vector<std::string> ChimpsetName, std::vector<std::string> ChimpsetType);
            ~Circuit();

            void createLinks(std::vector<std::string> linkNameSrc, std::vector<std::string> linkPinSrc, std::vector<std::string> linkNameDest, std::vector<std::string> linkPinDest);

            void allSimulate();
            void displayAll();
            void loop();

            void changeInput(std::string name, nts::Tristate);

        protected:
        private:
            size_t tick = 0;
            std::vector<nts::IComponent *> inputComponents;
            // std::vector<nts::IComponent *> clockComponents;
            std::vector<nts::IComponent *> outputComponents;
            std::map<std::string, nts::IComponent *> allComponents;
            std::vector<nts::IComponent *> listComponents;
    };
}


#endif /* !CIRCUIT_HPP_ */
