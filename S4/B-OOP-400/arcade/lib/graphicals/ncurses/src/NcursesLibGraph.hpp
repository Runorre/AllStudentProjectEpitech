/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesLibGraph
*/

#ifndef NCURSESLIBGRAPH_HPP_
    #define NCURSESLIBGRAPH_HPP_
    #include "../include/ncurses.hpp"

    class NcursesLibGraph : public IGraphlib {
        public:
            ~NcursesLibGraph();

            void menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores);
            int selectLibGraphic();
            int selectLibGame();
            std::string getNamePlayer();
            KeyEvent handlekeyevent();
            void showStaticbackground(std::vector<std::vector<std::string>> mapdecor);
            void showDynamicAssets(std::vector<IObject> assets);
            void showScore(int score);
            void init_windows(int height, int wight);
            void reset_windows();
            void display();
            void clear();
            void handleSelectionAndName(int& selectedOptionIndex, int maxY, std::string& playerName, int height, int width, int start_y, int start_x, WINDOW* win, const std::vector<std::string>& libgraphs, const std::vector<std::string>& libgames, const std::vector<std::vector<std::string>>& scores);

            void determineSelectedLibraryAndGame(int x, int y, const std::vector<std::string> libgraphs, const std::vector<std::string> libgames);

        protected:
        private:
            int game = -1;
            int graphical = -1;
            std::string username;
    };

#endif /* !NCURSESLIBGRAPH_HPP_ */
