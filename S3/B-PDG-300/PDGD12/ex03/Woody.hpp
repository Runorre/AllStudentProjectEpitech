/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_
#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string name);
        Woody(const std::string name, std::string ascii);

        void speak(std::string text) const;

    protected:
    private:
};

#endif /* !WOODY_HPP_ */
