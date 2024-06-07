/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** SFML
*/

#include "../../../../include/IGraphlib/IGraphlib.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#ifndef SFML_HPP_
#define SFML_HPP_


class SFML : public IGraphlib{
    public:
        SFML();
        ~SFML() override;
        void menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores) override;
        KeyEvent handlekeyevent() override;
        void showStaticbackground(std::vector<std::vector<std::string>> mapdecor) override;
        void showDynamicAssets(std::vector<IObject> assets) override;
        void showScore(int score) override;
        std::string getNamePlayer() override;
        int selectLibGraphic() override;
        int selectLibGame() override;
        void init_windows(int height, int widght) override;
        void reset_windows() override;
        void display() override;
        void clear() override;

        protected:
        private:
            int game = -1;
            int graphical = -1;
            std::string username;
            sf::RenderWindow window;
            sf::Event event;
            std::vector<std::vector<std::string>> background;
            std::vector<IObject *> assets;
};

#endif /* !SFML_HPP_ */
