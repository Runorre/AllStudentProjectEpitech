/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Background
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::istringstream;
using std::string;
using std::vector;
using std::invalid_argument;
using std::out_of_range;

enum class BackgroundObjects {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
};

class Background {
    public:
        Background() = default;
        explicit Background(SDL_Renderer *const renderer);
        ~Background() = default;
        void setBackground(const string &path, SDL_Renderer *const renderer, const size_t x, const size_t y);
        void getBackgroundObjects(const string &command);
        vector<vector<vector<int>>> getObject() const;
        vector<vector<SDL_Texture *>> getTextures() const;
        vector<SDL_Rect> getRects() const;
        [[nodiscard]] SDL_Texture *getObjectTexture(const int i) const;
        vector<string> split(const string &s, const char delimiter) const;
        vector<int> getNumberObjects();
    private:
        vector<vector<SDL_Texture *>> mTextures;
        vector<vector<vector<int>>> mBackgroundObjects = vector<vector<vector<int>>>(10, vector<vector<int>>(10, vector<int>(7, 0)));
        vector<SDL_Rect> mRects = {
            {0, 0, 0, 0},
            {20, 20, 40, 40},
            {80, 15, 50, 45},
            {140, 10, 45, 50},
            {200, 15, 50, 45},
            {260, 25, 60, 40},
            {330, 15, 40, 55},
        };
        SDL_Texture *mObjectTexture = nullptr;
        SDL_Texture *mFoodTexture = nullptr;
        vector<int> mNumberObjects = {0, 0, 0, 0, 0, 0, 0};
};
