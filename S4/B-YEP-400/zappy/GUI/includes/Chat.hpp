/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Chat
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string_view>
#include <vector>

using std::string;
using std::vector;
using std::string_view;

class Chat {
    public:
        Chat();
        void addMessage(const string &message);
        void render(SDL_Renderer *const renderer);
        void setCurrentMessage(const string &message);
        string getCurrentMessage() const;
    private:
        SDL_Rect mChatBox = {10, 10, 100, 950};
        TTF_Font *mFont;
        SDL_Color mTextColor = {255, 255, 255, 255};
        vector<string> mMessages;
        string mCurrentMessage = " ";
        string mLastMessage= " ";
};
