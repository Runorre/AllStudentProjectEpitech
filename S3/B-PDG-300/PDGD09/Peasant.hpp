/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Peasant
*/

#ifndef PEASANT_HPP_
#define PEASANT_HPP_
#include <string>
#include "ICharacter.hpp"

class Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        ~Peasant();

        const std::string &getName() const;
        int getPower() const;
        int getHp() const;

        virtual int attack();
        virtual int special();
        virtual void rest();
        void damage(int damage);

    protected:
        std::string _name;
        int attackGen(int dmg, std::string catchkill, int cost);
        void restGen(std::string catchrest, int regen, int regenHp);
    private:
        int _hp;
        int _power;
};

#endif /* !PEASANT_HPP_ */
