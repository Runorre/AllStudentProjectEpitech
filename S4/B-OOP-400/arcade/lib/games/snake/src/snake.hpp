/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** snake
*/

#include "../../../../include/IGamelib/IGamelib.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <random>

#ifndef Snake_HPP_
#define Snake_HPP_

class Food : public IObject{
public:
    Food();
    ~Food() override;
    int x;
    int y;
};

class ObjSnake : public IObject{
    public:
        ObjSnake();
        ~ObjSnake() override;
        std::vector<Food>& getFood();
        int timer = 0;
};

class ObjSnakeSnd : public IObject {
public:
    ObjSnakeSnd();
    ~ObjSnakeSnd() override;
    int timer = 0;
private:
};

class Snake : public IGamelib {
    public:
        Snake();
        ~Snake() override;
        std::vector<std::vector<std::string>> getStaticDecor() const override;
        std::vector<IObject> getObject() override;
        void setObject(std::vector<IObject> layer) override;
        int getScore() const override;
        std::string getName() const override;
        void sendCommand(int commande) override;
        bool isGameOver() const override;
        void init_map();

        void createSnake();
        void checkGameOver();
        void checkCollision();
        std::vector<IObject> game_loop();
        void add_score(int score);
        void generateFood();
        bool isSnakeBody(int x, int y);
        void checkCollisionWithFood();
        void growSnake();

    protected:
    private:
        std::vector<std::vector<std::string>> map;
        std::vector<IObject> layer;
        Food food;
        std::vector<ObjSnakeSnd> snakeSnd;
        ObjSnake snake;
        int score;
        bool gameover;
        int timer = 0;
        KeyEvent direction = UP;
};

#endif /* !Snake_HPP_ */