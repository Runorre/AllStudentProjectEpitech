/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGraphlib
*/

#ifndef IGRAPHLIB_HPP_
    #define IGRAPHLIB_HPP_
    #include "../Arcade.hpp"
    #include <vector>

    enum KeyEvent {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        PAUSE,
        CONFIRM,
        NEXTGAME,
        NEXTLIB,
        RESET,
        CLOSE
    };

    class IGraphlib {
        public:
            virtual ~IGraphlib() = default;

            virtual void menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores) = 0;
            virtual int selectLibGraphic() = 0;
            virtual int selectLibGame() = 0;
            virtual std::string getNamePlayer() = 0;
            virtual KeyEvent handlekeyevent() = 0;
            virtual void showStaticbackground(std::vector<std::vector<std::string>> mapdecor) = 0;
            virtual void showDynamicAssets(std::vector<IObject> assets) = 0;
            virtual void showScore(int score) = 0;
            virtual void display() = 0;
            virtual void clear() = 0;

            virtual void init_windows(int height, int wight) = 0;
            virtual void reset_windows() = 0;

        protected:
        private:
    };

#endif /* !IGRAPHLIB_HPP_ */