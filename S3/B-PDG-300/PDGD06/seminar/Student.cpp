/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** Student
*/

#include "Student.hpp"
#include <iostream>

Student::Student(std::string name)
{
    this->_name_ = name;
    this->_energy_ = 100;
    std::cout << "Student " << this->_name_ << ": I'm ready to learn C++." << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << this->_name_ << ": Wow, much learning today, very smart, such C++." << std::endl;
}

bool Student::learn(std::string text)
{
    if (this->_energy_ < 42) {
        size_t start_pos = 0;
        std::string tmpText = text;
        while((start_pos = tmpText.find("C++", start_pos)) != std::string::npos) {
            tmpText.replace(start_pos, 3, "shit");
            start_pos += 4;
        }
        std::cout << "Student " << this->_name_ << ": " << tmpText << std::endl;
        return false;
    } else {
        this->_energy_ -= 42;
        std::cout << "Student " << this->_name_ << ": " << text << std::endl;
        return true;
    }
}

void Student::drink(std::string drinkName)
{
    if (drinkName == "Red Bull") {
        std::cout << "Student " << this->_name_ << ": Red Bull gives you wings!" << std::endl;
        if ((this->_energy_ + 32) > 100)
            this->_energy_ = 100;
        else
            this->_energy_ += 32;
    } else if (drinkName == "Monster") {
        std::cout << "Student " << this->_name_ << ": Unleash The Beast!" << std::endl;
        if ((this->_energy_ + 64) > 100)
            this->_energy_ = 100;
        else
            this->_energy_ += 64;
    } else {
        std::cout << "Student " << this->_name_ << ": ah, yes... enslaved moisture." << std::endl;
        this->_energy_ += 1;
    }
}
