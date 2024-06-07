/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** Circuit
*/

#include "../../include/nanotekspice.hpp"
#include <vector>

nts::Circuit::Circuit(std::vector<std::string> ChimpsetName, std::vector<std::string> ChimpsetType)
{
    for (size_t i = 0; i < ChimpsetName.size(); ++i) {
        this->allComponents[ChimpsetName[i]] = nts::Factory::factoryCreator(ChimpsetType[i], ChimpsetName[i]);
        this->listComponents.push_back(this->allComponents[ChimpsetName[i]]);

        if (ChimpsetType[i] == "input" || ChimpsetType[i] == "clock") {
            this->inputComponents.push_back(this->allComponents[ChimpsetName[i]]);
        }
        else if (ChimpsetType[i] == "output") {
            this->outputComponents.push_back(this->allComponents[ChimpsetName[i]]);
        }
        // else if (ChimpsetType[i] == "clock") {
        //     this->clockComponents.push_back(this->allComponents[ChimpsetName[i]]);
        // }
    }

    
    std::sort(this->inputComponents.begin(), this->inputComponents.end(),
        [](const nts::IComponent *a, const nts::IComponent *b) {
            return a->getName() < b->getName();
        });
    std::sort(this->outputComponents.begin(), this->outputComponents.end(),
        [](const nts::IComponent *a, const nts::IComponent *b) {
            return a->getName() < b->getName();
        });
    
    // for (size_t i = 0; i < this->outputComponents.size(); ++i) {
    //     std::cout << "DEBUG TEST OUTPUT "<< i << " : " << outputComponents[i]->getName() << std::endl;
    // }
}

void nts::Circuit::createLinks(std::vector<std::string> linkNameSrc, std::vector<std::string> linkPinSrc, std::vector<std::string> linkNameDest, std::vector<std::string> linkPinDest) {
    for (size_t i = 0; i < linkNameSrc.size(); ++i) {
        std::size_t linkPinSrcSizeT = std::stoul(linkPinSrc[i]);
        std::size_t linkPinDestSizeT = std::stoul(linkPinDest[i]);
        this->allComponents[linkNameSrc[i]]->setLink(linkPinSrcSizeT, *this->allComponents[linkNameDest[i]], linkPinDestSizeT);
        // std::cout << "DEBUG LINK : " << linkNameSrc[i] << std::endl;
    }
}

void nts::Circuit::allSimulate() {
    std::vector<std::string> simulated(this->allComponents.size());
    std::queue<IComponent *> queueToExecuted;

    for (size_t i = 0; i < this->inputComponents.size(); ++i) {
        queueToExecuted.push(inputComponents[i]);
    }

    // for (size_t i = 0; i < this->clockComponents.size(); ++i) {
    //     queueToExecuted.push(clockComponents[i]);
    // }
    
    while (!queueToExecuted.empty()) {
        nts::IComponent *actually = queueToExecuted.front();
        if (!(std::find(simulated.begin(), simulated.end(), actually->getName()) != simulated.end())) {
            std::vector<std::string> inputname = actually->getAllInputs();
            bool verifiedElement = true;
            for (size_t i = 0; (i < inputname.size() && verifiedElement); ++i) {
                if (!(std::find(simulated.begin(), simulated.end(), inputname[i]) != simulated.end())) {
                    verifiedElement = false;
                    queueToExecuted.push(this->allComponents[inputname[i]]);
                }
                // std::cout << "DEBUG : SIMULATED - "<< actually->getName() << " | " << inputname[i] << std::endl;
            }
            if (verifiedElement) {
                actually->simulate(this->tick);
                std::map<std::size_t, nts::IComponent *> addingToQueue = actually->getLinks();

                for (const auto &pair : addingToQueue) {
                    queueToExecuted.push(pair.second);
                }

                simulated.push_back(actually->getName());
               
            } else {
                queueToExecuted.push(actually);
            }
            // for (const auto& component : simulated) {
            //     std::cout << "DEBUG : FINISHED SIMULATED - " << component << std::endl;
                
            // }
        }
        queueToExecuted.pop();
    }
    this->tick++;
}

/**
 * Displays the current state of the circuit.
 * Prints the tick value, input components, and output components.
 * If the program is running in a terminal, the output is formatted differently.
 */
void nts::Circuit::displayAll() {
    std::cout << "tick: " << this->tick << std::endl;
    if (isatty(0)) {
        std::cout << "input(s):" << std::endl;
    }
    else {
        std::cout << "input(s):" << std::endl;
    }
    for (size_t i = 0; i < this->inputComponents.size(); ++i) {
        if (isatty(0)) {
            std::cout << "\t" << inputComponents[i]->getName() << ": ";
        }
        else {
            std::cout << "  " << inputComponents[i]->getName() << ": ";
        }
        nts::Tristate state = inputComponents[i]->compute(1);
        if (state == nts::Undefined)
            std::cout << "U" << std::endl;
        else if (state == nts::True)
            std::cout << "1" << std::endl;
        else
            std::cout << "0" << std::endl;
    }
    // for (size_t i = 0; i < this->clockComponents.size(); ++i) {
    //     if (isatty(0)) {
    //         std::cout << "\t" << clockComponents[i]->getName() << ": ";
    //     }
    //     else {
    //         std::cout << "  " << clockComponents[i]->getName() << ": ";
    //     }
    //     nts::Tristate state = clockComponents[i]->compute(1);
    //     if (state == nts::Undefined)
    //         std::cout << "U" << std::endl;
    //     else if (state == nts::True)
    //         std::cout << "1" << std::endl;
    //     else
    //         std::cout << "0" << std::endl;
    // }
    if (isatty(0)) {
        std::cout << "output(s):" << std::endl;
    } else {
        std::cout << "output(s):" << std::endl;
    }
    for (size_t i = 0; i < this->outputComponents.size(); ++i) {
        if (isatty(0)) {
            std::cout << "\t" << outputComponents[i]->getName() << ": ";
        } else {
            std::cout << "  " << outputComponents[i]->getName() << ": ";
        }
        nts::Tristate state = outputComponents[i]->compute(1);
        if (state == nts::Undefined)
            std::cout << "U" << std::endl;
        else if (state == nts::True)
            std::cout << "1" << std::endl;
        else
            std::cout << "0" << std::endl;
    }
}

void nts::Circuit::loop() {
    while (1) {
        this->allSimulate();
        this->displayAll();
    }
}

void nts::Circuit::changeInput(std::string name, nts::Tristate state)
{
    for (size_t i = 0; i < this->inputComponents.size(); ++i) {
        if (this->inputComponents[i]->getName() == name) {
            this->inputComponents[i]->changeState(1, state);
            return;
        }
    }
    // for (size_t i = 0; i < this->clockComponents.size(); i++) {
    //     if (this->clockComponents[i]->getName() == name) {
    //         this->clockComponents[i]->changeState(1, state);
    //         return;
    //     }
    // }
    std::cerr << "Unknow component name '" << name << "'." << std::endl;
}

nts::Circuit::~Circuit() {
    for (size_t i = 0; i < this->listComponents.size(); ++i) {
        delete this->listComponents[i];
    }
}
