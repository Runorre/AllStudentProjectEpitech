/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** Student
*/

#ifndef STUDENT_HPP_
#define STUDENT_HPP_

#include <string>

class Student {
    public:
        std::string _name_;
        unsigned int _energy_;

        Student(std::string name);
        ~Student();
    
        bool learn(std::string text);
        void drink(std::string drinkName);

    private:
        
};

#endif /* !STUDENT_HPP_ */
