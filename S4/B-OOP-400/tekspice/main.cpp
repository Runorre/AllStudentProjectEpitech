/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** main
*/

#include "include/nanotekspice.hpp"
#include "include/IComponent.hpp"


int main(int argc, char **argv) 
{
    if (argc > 2 || argc == 1) {
        cerr << "We need a filepath";
        return 84;
    }
    std::string filename = argv[1];
    size_t pos = filename.find_last_of(".");
    
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        cout << "NANOTEKSPICE" << endl;
        cout << "\tUse a file with .chipsets and .links" << endl;

    } else {
        try {
            if (pos == std::string::npos || filename.substr(pos) != ".nts") {
                throw nts::IncorrectFile();
            }
            return parseFile(argv[1]);
        } catch (const nts::ParsingError& e) {
            cerr << e.what() << endl;
            return 84;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            return 84;
        }
    }
    return 0;
}
