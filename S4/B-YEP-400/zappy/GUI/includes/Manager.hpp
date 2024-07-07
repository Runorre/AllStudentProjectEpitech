/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Manager
*/

#pragma once

#include "../includes/Engine.hpp"
#include "../includes/IProcess.hpp"
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using std::atomic;
using std::queue;
using std::string;

class Manager {
    public:
        Manager(const Process &process, Engine &engine) : mProcess(process), mEngine(engine) {};
        ~Manager() = default;
        void runLoop(const int sizeMapX, const int sizeMapY);
        void receiveMessages();
        void addCommandToEngine(const string &command);
    private:
        Process mProcess;
        Engine &mEngine;
        queue<string> mQueue;
        atomic<bool> runningThread = true;
};
