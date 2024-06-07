/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** Dean
*/

#ifndef DEAN_HPP_
#define DEAN_HPP_
#include <string>
#include "Student.hpp"

class Dean {
    public:
        Dean(std::string name);
        ~Dean();

        void teachStudent(Student *student, std::string lesson);
        void timeCheck();

    private:
    std::string _name_;
    bool working;
};

#endif /* !DEAN_HPP_ */
