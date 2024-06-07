/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** Dean
*/

#include "Dean.hpp"
#include <iostream>
#include <fstream>
#include "Student.hpp"

Dean::Dean(std::string name)
{
    this->_name_ = name;
    this->working = false;
    std::cout << "Dean " << this->_name_ << ": I'm Dean " << this->_name_ << "! How do you do, fellow kids?" << std::endl;
}

Dean::~Dean()
{
    std::cout << "Dean " << this->_name_ <<  ": Time to go home." << std::endl;
}

void Dean::teachStudent(Student *student, std::string lesson)
{
    if (!student->learn(lesson)) {
        std::cout << "Dean " << this->_name_ <<  ": All work and no play makes " << student->_name_ << " a dull student." << std::endl;
        std::ofstream newFile(student->_name_ + ".drink");

        int randomDrink = std::rand() % 5;
        switch (randomDrink) {
        case 0:
            newFile << "Cristaline";
            break;
        case 1:
            newFile << "Monster";
            break;
        case 2:
            newFile << "Evian";
            break;
        case 3:
            newFile << "Red Bull";
            break;
        default:
            newFile << "Sierra Springs";
            break;
        }
        newFile.close();
    }
}

void Dean::timeCheck()
{
    if (this->working)
        std::cout << "Dean " << this->_name_ <<  ": Where is everyone?" << std::endl;
    else
        std::cout << "Dean " << this->_name_ <<  ": Don't forget to close the windows when you leave." << std::endl;
    this->working = !this->working;
}
