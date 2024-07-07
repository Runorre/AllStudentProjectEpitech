/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Window
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#pragma once

using std::string;

class Window {
    public:
        Window() = default;
        ~Window() = default;
        void createWindow(const string &title, const int width, const int height);
        void destroyWindow();
        [[nodiscard]] SDL_Window *getWindow() { return mWindow; }
        [[nodiscard]] SDL_Renderer *getRenderer() { return mRenderer; }
    private:
        SDL_Renderer *mRenderer;
        SDL_Window *mWindow;
};
