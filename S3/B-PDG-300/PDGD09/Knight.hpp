/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Knight
*/

#ifndef KNIGHT_HPP_
#define KNIGHT_HPP_
#include "Peasant.hpp"

class Knight : public virtual Peasant {
    public:
        Knight(const std::string &name, int power);
        ~Knight();

        int attack();
        virtual int special();
        virtual void rest();

    protected:
    private:
};

#endif /* !KNIGHT_HPP_ */
