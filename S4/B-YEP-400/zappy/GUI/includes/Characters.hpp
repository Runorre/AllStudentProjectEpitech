/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Characters
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include <iostream>
#include <random>
#include <string>

using std::mt19937;
using std::random_device;
using std::string;
using std::uniform_int_distribution;
using std::vector;

class Characters {
    public:
        Characters() = default;
        Characters(const int number, const int x, const int y, const int orientation, const int level);
        void setTexture(SDL_Renderer *const mRenderer);
        [[nodiscard]] SDL_Texture *getTexture() const;
        [[nodiscard]] SDL_Rect getRect() const;
        [[nodiscard]] int getNumber() const;
        [[nodiscard]] int getX() const;
        [[nodiscard]] int getY() const;
        [[nodiscard]] int getOrientation() const;
        [[nodiscard]] int getLevel() const;
        void setX(const int x);
        void setY(const int y);
        void setOrientation(const int orientation);
        [[nodiscard]] int getModifX() const;
        [[nodiscard]] int getModifY() const;
        void setTextRect(const SDL_Rect textRect);
        [[nodiscard]] SDL_Rect getTextRect() const;
        void setIsSelected(const bool isSelected);
        [[nodiscard]] bool getIsSelected() const;
        void setFood(const int food);
        void setLinemate(const int linemate);
        void setDeraumere(const int deraumere);
        void setSibur(const int sibur);
        void setMendiane(const int mendiane);
        void setPhiras(const int phiras);
        void setThystame(const int thystame);
        [[nodiscard]] int getFood() const;
        [[nodiscard]] int getLinemate() const;
        [[nodiscard]] int getDeraumere() const;
        [[nodiscard]] int getSibur() const;
        [[nodiscard]] int getMendiane() const;
        [[nodiscard]] int getPhiras() const;
        [[nodiscard]] int getThystame() const;
        [[nodiscard]] vector<int> getInventory() const;
        void setIncantation(const bool incantation);
        [[nodiscard]] bool getIncantation() const;
        void setIncantationX(const int incantationX);
        [[nodiscard]] int getIncantationX() const;
        void setLevel(const int level);
    private:
        SDL_Rect mTextRect;
        SDL_Texture *mTexture = nullptr;
        vector<SDL_Rect> mRects = {
            {5, 135, 55, 65},
            {5, 200, 55, 65},
            {5, 5, 55, 65},
            {5, 70, 55, 65}
        };
        int mModifY = 0;
        int mModifX = 0;
        int mNumber = 0;
        int mX = 0;
        int mY = 0;
        int mOrientation = 1;
        int mLevel = 1;
        bool mIsSelected = false;
        int mFood = 0;
        int mLinemate = 0;
        int mDeraumere = 0;
        int mSibur = 0;
        int mMendiane = 0;
        int mPhiras = 0;
        int mThystame = 0;
        bool mIncantation = false;
        int mIncantationX = 0;
};

