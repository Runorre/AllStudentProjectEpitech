/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Window
*/

#include "../includes/Window.hpp"

void Window::createWindow(const string &title, const int width, const int height)
{
    mWindow = ::SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (mWindow == nullptr) {
        return;
    }
    mRenderer = ::SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mRenderer == nullptr) {
        return;
    }
}

void Window::destroyWindow()
{
    ::SDL_DestroyRenderer(mRenderer);
    ::SDL_DestroyWindow(mWindow);
}
