/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Enchanter
*/

#ifndef ENCHANTER_HPP_
#define ENCHANTER_HPP_
#include "Peasant.hpp"

class Enchanter : public virtual Peasant {
    public:
        Enchanter(const std::string &name, int power);
        ~Enchanter();

        virtual int attack();
        int special();
        virtual void rest();

    protected:
    private:
};

#endif /* !ENCHANTER_HPP_ */
