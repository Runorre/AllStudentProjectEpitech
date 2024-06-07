/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** pacman
*/

#include "../../../../include/IGamelib/IGamelib.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cmath>

#ifndef PACMAN_HPP_
#define PACMAN_HPP_


class ObjPacman : public IObject{
    public:
        ObjPacman();
        ~ObjPacman() override;
        int timer = 0;
};

class Objdot : public IObject{
    public:
        Objdot();
        ~Objdot() override;
};

class Objgums : public IObject{
    public:
        Objgums();
        ~Objgums() override;
};

class ObjGhost : public IObject{
    public:
        ObjGhost();
        ~ObjGhost() override;
        bool GhostOutside = false;
        bool GhostEatable = false;
        KeyEvent direction = NONE;
        int timer = 0;
        std::string basepath;
};

class Pacman : public IGamelib {
    public:
        Pacman();
        ~Pacman() override;
        std::vector<std::vector<std::string>>getStaticDecor() const override;
        std::vector<IObject> getObject() override;
        std::vector<IObject> game_loop();
        void setObject(std::vector<IObject> layer) override;
        int getScore() const override;
        std::string getName() const override;
        void sendCommand(int commande) override;
        // std::vector<IObject> moove_charac(int moove) override;
        void init_map();
        void add_score(int score);
        std::vector<Objdot> getDots();
        std::vector<Objgums> getGums();
        std::vector<ObjGhost> getGhosts();
        ObjPacman getPacman();
        bool isGameOver() const override;
    protected:
    private:
        int timer = 0;
        std::vector<std::vector<std::string>> map;
        std::vector<IObject>layer;
        std::vector<Objdot>dots;
        std::vector<Objgums>gums;
        std::vector<ObjGhost>ghosts;
        KeyEvent direction = NONE;
        ObjPacman pacman;
        int score;
        bool gameover;
};

#endif /* !PACMAN_HPP_ */
