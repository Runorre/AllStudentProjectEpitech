/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** ICharacter
*/

#ifndef ICHARACTER_HPP_
#define ICHARACTER_HPP_
#include <string>

class ICharacter {
    public:

        virtual ~ICharacter() = default;

        virtual const std::string &getName() const = 0;
        virtual int getPower() const = 0;
        virtual int getHp() const = 0;
        virtual void damage(int damage) = 0;


        virtual int attack() = 0;
        virtual int special() = 0;
        virtual void rest() = 0;
        
        

    protected:
    private:
};

#endif /* !ICHARACTER_HPP_ */
