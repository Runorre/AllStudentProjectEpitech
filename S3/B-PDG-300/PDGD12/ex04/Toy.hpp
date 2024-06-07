/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include <string>
#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        enum ToyType {
            BASIC_TOY,
            ALIEN,
            BUZZ,
            WOODY
        };

        Toy(ToyType type, std::string name, std::string fileName);
        Toy(const Toy &t);
        Toy();
        ~Toy();

        ToyType getType() const;
        std::string getName() const;
        void setName(std::string name);
        bool setAscii(std::string fileName);
        std::string getAscii() const;

        virtual void speak(std::string text) const;

        Toy &operator<<(const std::string &ascii);
        Toy &operator=(const Toy &source);

    protected:
    private:
        ToyType _type_;
        std::string _name_;
        Picture *_ascii_;
};

std::ostream &operator<<(std::ostream &os, const Toy &t);

#endif /* !TOY_HPP_ */
