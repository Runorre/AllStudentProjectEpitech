/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** ACitrus
*/

#ifndef ACITRUS_HPP_
#define ACITRUS_HPP_
#include "AFruit.hpp"

class ACitrus : public AFruit {
    public:
        ACitrus(std::string name, unsigned int vitamin);
        ~ACitrus();

    protected:
    private:
};

#endif /* !ACITRUS_HPP_ */
