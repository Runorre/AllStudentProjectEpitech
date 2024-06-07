/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** Assistant
*/

#include "Assistant.hpp"
#include "Student.hpp"
#include <iostream>
#include <string>
#include <fstream>

Assistant::Assistant(unsigned int id)
{
    this->_id_ = id;
    this->working = false;
    std::cout << "Assistant " << this->_id_ << ": 'morning everyone *sip coffee*" << std::endl;

}

Assistant::~Assistant()
{
    std::cout << "Assistant " << this->_id_ << ": see you tomorrow at 9.00 *sip coffee*" << std::endl;
}

void Assistant::giveDrink(Student *kid, std::string drink)
{
    std::cout << "Assistant " << this->_id_ << ": drink this, " << kid->_name_ << " *sip coffee*" << std::endl;
    kid->drink(drink);
}

std::string Assistant::readDrink(std::string studentName)
{
    std::string nameFile = "./" + studentName + ".drink";
    std::ifstream file(nameFile);

    if (!file)
        return "";
    std::string line;
    std::getline(file, line);
    if (line.empty())
        return "";
    
    std::cout << "Assistant " << this->_id_ << ": " << studentName << " needs a " << line << " *sip coffee*" << std::endl;
    remove(nameFile.c_str());
    return line;
}

void Assistant::helpStudent(Student *student)
{
    std::string drinkName = this->readDrink(student->_name_);
    if (drinkName.empty()) {
        std::cout << "Assistant " << this->_id_ << ": " << student->_name_ << " seems fine *sip coffee*" << std::endl;
        return;
    }
    this->giveDrink(student, drinkName);
}

void Assistant::timeCheck(void)
{
    if (this->working)
        std::cout << "Assistant " << this->_id_ << ": Enough teaching for today *sip coffee*" << std::endl;
    else
        std::cout << "Assistant " << this->_id_ << ": Time to teach some serious business *sip coffee*" << std::endl;
    this->working = !this->working;
}
