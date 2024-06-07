/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** menu
*/

#include "SFML.hpp"

std::vector<std::string> end(std::vector<sf::Text>& games, std::vector<sf::Text>& graphical, std::string inputText)
{
    std::vector<std::string> returnlib;
    for (long unsigned int j = 0; j < games.size(); j++) {
        if (games[j].getFillColor() == sf::Color::Red) {
            returnlib.push_back(games[j].getString().toAnsiString());
        }
    }
    for (long unsigned int j = 0; j < graphical.size(); j++) {
        if (graphical[j].getFillColor() == sf::Color::Red) {
            returnlib.push_back(graphical[j].getString().toAnsiString());
        }
    }
    returnlib.push_back(inputText);
    return returnlib;
}

void type_events(std::vector<sf::Text>& games, std::vector<sf::Text>& graphical, sf::Vector2f mousePosition)
{
    for (long unsigned int j = 0; j < games.size(); j++) {
        if (games[j].getGlobalBounds().contains(mousePosition)) {
            if (games[j].getFillColor() == sf::Color::White)
                games[j].setFillColor(sf::Color::Cyan);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for (long unsigned int k = 0; k < games.size(); k++) {
                    games[k].setFillColor(sf::Color::White);
                }
                games[j].setFillColor(sf::Color::Red);
            }
        }
        else if (games[j].getFillColor() == sf::Color::Cyan) {
            games[j].setFillColor(sf::Color::White);
        }
    }
    for (long unsigned int j = 0; j < graphical.size(); j++) {
        if (graphical[j].getGlobalBounds().contains(mousePosition)) {
            if (graphical[j].getFillColor() == sf::Color::White)
                graphical[j].setFillColor(sf::Color::Cyan);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                for (long unsigned int k = 0; k < graphical.size(); k++) {
                    graphical[k].setFillColor(sf::Color::White);
                }
                graphical[j].setFillColor(sf::Color::Red);
            }
        }
        else if (graphical[j].getFillColor() == sf::Color::Cyan) {
            graphical[j].setFillColor(sf::Color::White);
        }
    }
}

std::string setName(std::string inputText, sf::Event event)
{
     if (event.text.unicode < 128)
    {
        if (event.text.unicode == 8 && inputText.size() > 0)
            inputText.erase(inputText.size() - 1);
        else if (event.text.unicode != 13)
                    inputText += static_cast<char>(event.text.unicode);
    }
    return inputText;
}

sf::Text create_text(std::string str, std::vector<int> pos, sf::Font &font)
{
    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos[0], pos[1]);
    return text;
}


void SFML::menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores)
{
    std::vector<std::string> returnlib;
    int i = 0;
    sf::Font font;
    std::string inputText;
    if (!font.loadFromFile("lib/graphicals/assets/Graphical/font.ttf"))
        exit(84);
    std::vector<sf::Text> titles;
    std::vector<sf::Text> games;
    std::vector<sf::Text> graphical;
    std::vector <sf::Text> scores_text;
    std::vector<std::vector<sf::Text>> texts;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    titles.push_back(create_text("Choose a graphical library", {380, 0}, font));
    titles.push_back(create_text("Choose a game library", {0, 0}, font));
    titles.push_back(create_text("Name :", {0, 250}, font));
    for (long unsigned int j = 0; j < libgraphs.size(); j++) {
        sf::Text text = create_text(libgraphs[j], {520, 50 + (int) j * 50}, font);
        graphical.push_back(text);
    }
    for (long unsigned int j = 0; j < libgames.size(); j++) {
        sf::Text text = create_text(libgames[j], {100, 50 + (int) j * 50}, font);
        games.push_back(text);
    }
    for (long unsigned int j = 0; j < scores.size(); j++) {
        for (long unsigned int k = 0; k < scores[j].size(); k++) {
            sf::Text text = create_text(scores[j][k], {250 + (int) k * 150, 400 + (int) j * 50}, font);
            scores_text.push_back(text);
        }
    }
    sf::Text name = create_text(inputText, {100, 250}, font);
    sf::Text Start = create_text("Start", {300, 300}, font);
    sf::Text score = create_text("Score :", {275, 350}, font);
    texts.push_back(titles);
    texts.push_back(graphical);
    texts.push_back(games);
    while (window.isOpen()) {
        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        sf::Event event;
        for (long unsigned int j = 0; j < titles.size(); j++) {
            window.draw(titles[j]);
        }
        for (long unsigned int j = 0; j < graphical.size(); j++) {
            window.draw(graphical[j]);
        }
        for (long unsigned int j = 0; j < games.size(); j++) {
            window.draw(games[j]);
        }
        for (long unsigned int j = 0; j < scores_text.size(); j++) {
            window.draw(scores_text[j]);
        }
        if (i == 3)
            window.draw(Start);
        window.draw(name);
        window.draw(score);
        window.display();
        window.clear();
        while (window.pollEvent(event)) {
            type_events(games, graphical, mousePosition);
            if (i == 3 && Start.getGlobalBounds().contains(mousePosition)) {
                Start.setFillColor(sf::Color::Cyan);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    returnlib = end(games, graphical, inputText);
                    for (long unsigned int j = 0; j < libgames.size(); j++) {
                        if (returnlib[0] == libgames[j]) {
                            this->game = j;
                        }
                    }
                    for (long unsigned int j = 0; j < libgraphs.size(); j++) {
                        if (returnlib[1] == libgraphs[j]) {
                            this->graphical = j;
                        }
                    }
                    this->username = returnlib[2];
                    window.close();
                }
            } else if (i == 3 && Start.getFillColor() == sf::Color::Cyan) {
                Start.setFillColor(sf::Color::White);
            }
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 && inputText.size() > 0)
                        inputText.erase(inputText.size() - 1);
                    else if (event.text.unicode != 13)
                        inputText += static_cast<char>(event.text.unicode);
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        name.setString(inputText);
        
        for (long unsigned int j = 0; j < graphical.size(); j++) {
            for (long unsigned int k = 0; k < games.size(); k++) {
                if (games[k].getFillColor() == sf::Color::Red &&
                graphical[j].getFillColor() == sf::Color::Red && inputText.size() > 0) {
                    i = 3;
                }
            }
        }
    }
}
