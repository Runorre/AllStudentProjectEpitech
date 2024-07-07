/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Egg
*/

#include "../includes/Egg.hpp"

Egg::Egg(const int number, const int x, const int y) : mNumber(number), mX(x), mY(y) {}

void Egg::setTexture(SDL_Renderer *const mRenderer)
{
    SDL_Surface *const surface = ::IMG_Load("GUI/assets/spaceship.png");
    if (surface == nullptr) {
        return;
    }
    mTexture = ::SDL_CreateTextureFromSurface(mRenderer, surface);
    if (mTexture == nullptr) {
        return;
    }
    ::SDL_FreeSurface(surface);
}

SDL_Texture *Egg::getTexture() const
{
    return mTexture;
}

void Egg::setNumber(const int number)
{
    mNumber = number;
}

int Egg::getNumber() const
{
    return mNumber;
}

void Egg::setX(const int x)
{
    mX = x;
}

int Egg::getX() const
{
    return mX;
}

void Egg::setY(const int y)
{
    mY = y;
}

int Egg::getY() const
{
    return mY;
}
