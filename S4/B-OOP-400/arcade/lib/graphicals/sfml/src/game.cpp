/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** game
*/

#include "SFML.hpp"

void SFML::init_windows(int height, int widght)
{
    this->window.create(sf::VideoMode(widght, height), "Arcade");
    this->window.setFramerateLimit(30);
}

void SFML::reset_windows()
{
    this->window.close();
}

void SFML::showStaticbackground(std::vector<std::vector<std::string>> mapdecor)
{
    for (long unsigned int i = 0; i < mapdecor.size(); i++) {
        for (long unsigned int j = 0; j < mapdecor[i].size(); j++) {
            if (mapdecor[i][j] == "2") {
                sf::RectangleShape rectangle(sf::Vector2f(20, 20));
                rectangle.setPosition(j * 20, i * 20);
                rectangle.setFillColor(sf::Color::Blue);
                this->window.draw(rectangle);
            } else if (mapdecor[i][j] == "1") {
                sf::RectangleShape rectangle(sf::Vector2f(20, 20));
                rectangle.setPosition(j * 20, i * 20);
                rectangle.setFillColor(sf::Color::Cyan);
                this->window.draw(rectangle);
            }
        }
    }
}

void SFML::showDynamicAssets(std::vector<IObject> assets)
{
    for (long unsigned int i = 0; i < assets.size(); i++) {
        sf::Texture texture;
        if (assets[i].path != "10" && assets[i].path != "5") {
            texture.loadFromFile(assets[i].path);
            sf::IntRect frameRect(assets[i].rect[0], assets[i].rect[1], assets[i].rect[2], assets[i].rect[3]);
            sf::Sprite sprite(texture); 
            sprite.setTextureRect(frameRect);
            sprite.setPosition(assets[i].x * 20, assets[i].y * 20);
            this->window.draw(sprite);
        }
        else if (assets[i].path == "10") {
            sf::CircleShape circle(10);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(assets[i].x * 20, assets[i].y * 20);
            this->window.draw(circle);
        }
        else if (assets[i].path == "5") {
            sf::CircleShape circle(5);
            circle.setFillColor(sf::Color::Yellow);
            circle.setPosition(assets[i].x * 20 + 0.5, assets[i].y * 20 + 0.5);
            circle.setFillColor(sf::Color::Yellow);
            this->window.draw(circle);
        }
    }
}

void SFML::showScore(int score)
{
    sf::Font font;
    font.loadFromFile("lib/graphicals/assets/Graphical/font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("Score: " + std::to_string(score));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(0, 0);
    this->window.draw(text);
}

KeyEvent SFML::handlekeyevent()
{
    while (this->window.pollEvent(this->event)) {
        if (event.type == sf::Event::Closed) {
            return CLOSE;
        }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z)
                    return UP;
                else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                    return DOWN;
                else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q)
                    return LEFT;
                else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
                    return RIGHT;
                else {
                    switch (event.key.code) {
                        case sf::Keyboard::Enter:
                            return CONFIRM;
                        case sf::Keyboard::Space:
                            return PAUSE;
                        case sf::Keyboard::R:
                            return RESET;
                        case sf::Keyboard::N:
                            return NEXTGAME;
                        case sf::Keyboard::M:
                            return NEXTLIB;
                        case sf::Keyboard::Escape:
                            return CLOSE;
                        default:
                            return NONE;
                    }
                }
            }
    }
    return NONE;
}