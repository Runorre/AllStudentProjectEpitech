/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Layer
*/

#pragma once

#include "Chat.hpp"
#include "Egg.hpp"
#include "ILayer.hpp"
#include <algorithm>
#include <iostream>
#include <map>

using std::cerr;
using std::map;
using std::to_string;
using std::hash;

class Layer : public ILayer{
    public:
        Layer() = default;
        explicit Layer(SDL_Renderer *const renderer);
        ~Layer() override = default;
        void printPlayer() override;
        void setObject(const int x, const int y) override;
        void printBackground() override;
        void printAll();
        [[nodiscard]] map<string, vector<Characters>> getPlayers() const;
        void setMap(const size_t sizeMapX, const size_t sizeMapY, SDL_Window *const window);
        void getBackgroundObjects(const string &command);
        void handleClick(const int mouseX, const int mouseY);
        void displayParcelInfo(const int x, const int y);
        void displayParcelInfo(const Characters &character);
        void addMessage(const int id, const string &message);
        void setCurrentMessage(const string &message);
        string getCurrentMessage() const;
        void setEggs(vector<Egg> const &eggs);
        void printEggs();
        vector<Egg> getEggs() const;
        [[nodiscard]] SDL_Renderer *getRenderer();
        void addCharacter(const Characters &character, const string &team);
        void moveCharacter(const int id, const int x, const int y, const int orientation);
        void updateInventory(const int id, const int food, const int linemate, const int deraumere, const int sibur, const int mendiane, const int phiras, const int thystame);
        void startIncantation(const int id);
        void stopIncantation(const int x, const int y);
        void updateLevel(const int id, const int level);
        void deletePlayer(const int id);
        void displayInfo();
        [[nodiscard]] bool isPointInRect(const int x, const int y, const SDL_Rect &rect) const;
    private:
        vector<int> mLastPos;
        vector<vector<SDL_Rect>> mRectMap;
        vector<vector<SDL_Rect>> mRectSprites;
        map<string, vector<Characters>> mPlayers;
        vector<Egg> mEggs;
        SDL_Renderer *mRenderer;
        SDL_Texture *mBack;
        Background mBackground;
        TTF_Font *mFont;
        vector<string> mObjectName = {
            "FOOD: ",
            "LINEMATE: ",
            "DERAUMERE: ",
            "SIBUR: ",
            "MENDIANE: ",
            "PHIRAS: ",
            "THYSTAME: ",
        };
        Chat mChat;
        Uint32 startTime = ::SDL_GetTicks();
        size_t nNbrPlayerDead = 0;
};
