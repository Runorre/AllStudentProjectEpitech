/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** main
*/

#include "MyGKrellM.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Choose whether you want the text or graphics version by typing the desired word :" << std::endl;
        std::cout << "Text or Graphical ?" << std::endl;

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "Text" || choice == "text") {
            Curse curseDisplay;
            int ch;
            timeout(1000);
            
            while (true) {
                curseDisplay.show();
                refresh();
                ch = getch();
                if (ch == 3) {
                    endwin();
                    exit(0);
                }
            }
            endwin();
            return 0;
        } else if (choice == "Graphical" || choice == "graphical") {
            SFMLDisplay sfml;
            sfml.show();
        } else {
            std::cout << "Invalid choice. Exiting program." << std::endl;
            return 84;
        }
        return 0;
    } else if (argc == 2) {
        std::string choice = argv[1];
        if (choice == "-G" || choice == "-g") {
            SFMLDisplay sfml;
            sfml.show();
            return 0;
        } else if (choice == "-T" || choice == "-t") {
            Curse curseDisplay;
            int ch;
            timeout(1000);
            
            while (true) {
                curseDisplay.show();
                refresh();
                ch = getch();
                if (ch == 3) {
                    endwin();
                    exit(0);
                }
            }
            endwin();
            return 0;
        } else {
            std::cout << "Invalid choice. Exiting program." << std::endl;
            return 84;
        }
    } else {
        return 84;
    }
    

    
    return 0;
}

// int main(void) {
//     bool choosing = true;
//     std::cout << "Choose whether you want the text or graphics version by typing the desired word :" << std::endl;
//     std::cout << "Text or Graphical ?" << std::endl;
//     std::string text;

//     while (choosing) {
//        std::getline(std::cin, text);
//        if (text != "Text" && text != "Graphical") {
//           std::cout << "Wrong input" << std::endl;
//           std::cout << "Text or Graphical ?" << std::endl;
//        } else {
//           choosing = false;
//        }
//     }

//     if (text == "text") {
//         std::cout << "TEXT" << std::endl;
//     } else {
//         std::cout << "GRAPH" << std::endl;
//     }
// }

//ici

//    //CpuModule cpu;
//    while (1) {
//       // cpu.displayCores();
//       // cpu.update();
//       std::cout << "coucou" << std::endl;
//    }
//    return 0;
// }

//!fonction test pour update cpu;
// int main(void)
// {
//    CpuModule cpu;

//    size_t i = 1;
//    while (true) {
//       std::cout << "tour de boucle = " << i << std::endl;
//       cpu.displayCores();
//       cpu.update();
//       sleep(1);
//       i ++;
//    }
//    return 0;
// }



// int main(void)
// {
//     SFMLDisplay sfml;
//     sfml.show();
//     return 0;
// }
