/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ILayer
*/

#pragma once

#include "Background.hpp"
#include "Characters.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::map;
using std::vector;

class ILayer {
    public:
        virtual ~ILayer() = default;
        virtual void printPlayer() = 0;
        virtual void setObject(const int x, const int y) = 0;
        virtual void printBackground() = 0;
};
