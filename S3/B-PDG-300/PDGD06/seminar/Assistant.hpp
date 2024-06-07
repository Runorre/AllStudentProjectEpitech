/*
** EPITECH PROJECT, 2024
** Day06
** File description:
** Assistant
*/

#ifndef ASSISTANT_HPP_
#define ASSISTANT_HPP_
#include "Student.hpp"
#include <string>

class Assistant {
    public:
        Assistant(unsigned int id);
        ~Assistant();

        void giveDrink(Student *kid, std::string drink);
        std::string readDrink(std::string studentName);
        void helpStudent(Student *student);
        void timeCheck(void);
    private:
        unsigned int _id_;
        bool working;
};

#endif /* !ASSISTANT_HPP_ */
