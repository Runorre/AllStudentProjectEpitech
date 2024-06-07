/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** SDL
*/

#include "../../../../include/Arcade.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#ifndef SDL_HPP_
#define SDL_HPP_

    class SDL : public IGraphlib {
        public:
            ~SDL();
        
            void menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores);
            int selectLibGraphic();
            int selectLibGame();
            std::string getNamePlayer();
            KeyEvent handlekeyevent();
            void showStaticbackground(std::vector<std::vector<std::string>> mapdecor);
            void showDynamicAssets(std::vector<IObject> assets);
            void showScore(int score);
            void display();
            void clear();
            void init_windows(int height, int width);
            void reset_windows();

            void determineSelectedLibraryAndGame(int x, int y, std::vector<std::string> libgraphs, std::vector<std::string> libgames);
            void handleEvents(SDL_Event &event, bool &running, bool &nameVisible, bool &typingText, std::string &userInput, SDL_Rect &rect,
                  std::vector<std::string> libgraphs, std::vector<std::string> libgames, bool &startAvailable);
            void renderText(SDL_Renderer* renderer, TTF_Font* font, bool nameVisible, std::string userInput, SDL_Rect rect);
            void initializeSDL(SDL_Window* &window, SDL_Renderer* &renderer, TTF_Font* &font);
            void cleanupSDL(SDL_Window* window, SDL_Renderer* renderer, TTF_Font* font);

        protected:
        private:
            int game = -1;
            int graphical = -1;
            std::string username;
            SDL_Renderer *renderer;
            SDL_Window *window;
            int frameTimer;
    };

#endif /* !SDL_HPP_ */
