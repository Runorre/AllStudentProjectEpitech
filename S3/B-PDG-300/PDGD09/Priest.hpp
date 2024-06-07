/*
** EPITECH PROJECT, 2024
** Day09
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_
#include "Enchanter.hpp"

class Priest : public virtual Enchanter {
    public:
        Priest(const std::string &name, int power);
        ~Priest();

        void rest();

    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
