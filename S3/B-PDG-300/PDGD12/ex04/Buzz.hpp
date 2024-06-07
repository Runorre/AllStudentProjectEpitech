/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_
#include "Toy.hpp"

class Buzz : public Toy {
    public:
        Buzz(const std::string name);
        Buzz(const std::string name, std::string ascii);

        void speak(std::string text) const;

    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
