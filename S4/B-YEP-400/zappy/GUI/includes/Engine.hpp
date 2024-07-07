/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Engine
*/

#pragma once

#include "Background.hpp"
#include "Layer.hpp"
#include "Server.hpp"
#include "Teams.hpp"
#include "Window.hpp"
#include <iostream>
#include <mutex>
#include <queue>
#include <random>
#include <regex>
#include <thread>

using std::atomic;
using std::cout;
using std::mt19937;
using std::mutex;
using std::queue;
using std::random_device;
using std::regex;
using std::size_t;
using std::smatch;
using std::string;
using std::thread;
using std::uniform_int_distribution;
using std::vector;

class Engine {
    public:
        Engine() {
            mWindow.createWindow("Zappy", 1920, 1080);
            mLayer = Layer(mWindow.getRenderer());
        }
        void runLoop(const size_t sizeMapX, const size_t sizeMapY);
        void selectionAction(const string &command);
        void processMessages();
        void getTeams(vector<string> &teams);
        void getSpawPlayer(const string &command);
        void moveCharacter(const string &command);
        vector<string> split(const string &s, const char delimiter) const;
        void setNetwork(const Network &network);
        void setProcess(const Process &process);
        void updateInventory(const string &command);
        void startIncantation(const string &command);
        void stopIncantation(const string &command);
        void broadcast(const string &command);
        void endGame(const string &command);
        void levelUp(const string &command);
        void deletePlayer(const string &command);
        void getSpawnEgg(const string &command);
        void addQueue(const string &command);
        [[nodiscard]] mutex &getMutex();
        void handleMouseButtonDownEvent(const SDL_Event &event, int &mouseX, int &mouseY) const;
        void handleKeyDownEvent(const SDL_Event &event, bool &running);
        void handleTextInputEvent(const SDL_Event &event);
    private:
        Window mWindow;
        Layer mLayer;
        vector<string> mTeams;
        Network mNetwork;
        Process mProcess;
        int totalPlayers = 0;
        atomic<bool> runningThread = true;
        queue<string> mQueue;
        mutex mMutex;
};
