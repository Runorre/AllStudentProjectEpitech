/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Egg
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <random>
#include <string>

using std::mt19937;
using std::random_device;
using std::string;
using std::uniform_int_distribution;

class Egg {
    public:
        Egg(const int number, const int x, const int y);
        ~Egg() = default;
        void setTexture(SDL_Renderer *const mRenderer);
        [[nodiscard]] SDL_Texture *getTexture() const;
        void setNumber(const int number);
        [[nodiscard]] int getNumber() const;
        void setX(const int x);
        [[nodiscard]] int getX() const;
        void setY(const int y);
        [[nodiscard]] int getY() const;
    private:
        SDL_Texture *mTexture;
        int mNumber;
        int mX;
        int mY;
};
