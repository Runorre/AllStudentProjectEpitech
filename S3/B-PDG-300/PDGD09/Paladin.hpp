/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_
#include "Knight.hpp"
#include "Priest.hpp"

class Paladin : public virtual Knight, public virtual Priest {
    public:
        Paladin(const std::string &name, int power);
        ~Paladin();

        int attack();
        int special();
        void rest();

    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
