/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML()
{
}

SFML::~SFML()
{
}

std::string SFML::getNamePlayer()
{
    return this->username;
}

int SFML::selectLibGraphic()
{
    return this->graphical;
}

int SFML::selectLibGame()
{
    return this->game;
}

void SFML::display()
{
    this->window.display();
}

void SFML::clear()
{
    this->window.clear();
}

extern "C" IGraphlib *instanceGraph()
{
    return new SFML();
}


