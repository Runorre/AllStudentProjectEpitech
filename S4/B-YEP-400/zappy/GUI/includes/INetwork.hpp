/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** INetwork
*/

#pragma once

#include <iostream>
#include <string>

using std::string;

class INetwork {
    public:
        virtual ~INetwork() = default;
        virtual void connect() = 0;
};
