/*
** EPITECH PROJECT, 2024
** Day07PM
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_
#include <string>

class Arms {
    protected:
        std::string _serial;
    private:
        bool _functional;
    public:
        Arms(const std::string &serial="A-01", bool functional = true);

        bool isFunctional();
        std::string serial();
        void informations();

};

class Legs {
    protected:
        std::string _serial;
    private:
        bool _functional;
    public:
        Legs(const std::string &serial="L-01", bool functional = true);

        bool isFunctional();
        std::string serial();
        void informations();

};

class Head {
    protected:
        std::string _serial;
    private:
        bool _functional;
    public:
        Head(const std::string &serial="H-01", bool functional = true);

        bool isFunctional();
        std::string serial();
        void informations();

};

#endif /* !PARTS_HPP_ */
