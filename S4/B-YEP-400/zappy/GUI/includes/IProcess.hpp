/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** IProcess
*/

#pragma once

#include <iostream>
#include <string>

using std::string;

class IProcess {
    public:
        virtual ~IProcess() = default;
        virtual void send_message(const string &message) = 0;
        virtual string receive_message() const = 0;
};
