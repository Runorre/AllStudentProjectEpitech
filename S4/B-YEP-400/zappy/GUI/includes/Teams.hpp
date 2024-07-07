/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Teams
*/

#pragma once

#include "Characters.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using std::make_tuple;
using std::map;
using std::mt19937;
using std::random_device;
using std::string;
using std::tuple;
using std::uniform_int_distribution;
using std::vector;

static const map<string, tuple<tuple<int, int, int>, string>> colors = {
    {"red", make_tuple(make_tuple(255, 0, 0), "character_red.png")},
    {"green", make_tuple(make_tuple(0, 255, 0), "character_base.png")},
    // {"blue", make_tuple(make_tuple(0, 0, 255), "character_blue.png")},
};

class Teams {
    public:
        Teams() = default;
        explicit Teams(const string &teamName);
        ~Teams() = default;
        void addCharacter(const Characters &character);
        vector<Characters> getCharacters() const;
    private:
        string pathColor;
        vector<Characters> mCharacters;
        tuple<int, int, int> mColor;
        string mTeamName;
};
