/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Manager
*/

#include "../includes/Manager.hpp"

void Manager::runLoop(const int sizeMapX, const int sizeMapY)
{
    thread receiver(&Manager::receiveMessages, this);
    mEngine.runLoop(sizeMapX, sizeMapY);
    runningThread = false;
    receiver.join();
}

void Manager::addCommandToEngine(const string &command)
{
    const std::scoped_lock lock(mEngine.getMutex());
    mEngine.addQueue(command);
}

void Manager::receiveMessages()
{
    int i = 0;
    while (runningThread) {
        const string command = mProcess.receive_message();
        i++;
        addCommandToEngine(command);
    }
}
