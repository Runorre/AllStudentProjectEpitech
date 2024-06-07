/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main
*/

#include "snake.hpp"

void Snake::init_map()
{
    this->map = {
        {"1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "1"},
        {"1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1"}};

    snake.x = 15;
    snake.y = 18;
    snake.path = "./lib/graphicals/assets/snake/aled.png";
    snake.coord = {37, 0};
    snake.name = "Snake";
    snake.rect = {0, 0, 21, 18};

    // corps début
    ObjSnakeSnd bodyPart1;
    bodyPart1.x = 15;
    bodyPart1.y = 19;
    bodyPart1.rect = {0, 0, 21, 18};
    bodyPart1.name = "Body";
    bodyPart1.path = "./lib/graphicals/assets/snake/body.png";
    bodyPart1.coord = {37, 0};
    bodyPart1.rect = {0, 0, 21, 18};

    // corps reste
    for (int i = 0; i < 2; ++i)
    {
        ObjSnakeSnd bodyPart;
        bodyPart.x = 15;
        bodyPart.y = 20 + i;
        bodyPart.path = "./lib/graphicals/assets/snake/body.png";
        bodyPart.coord = {37, 0};
        bodyPart.rect = {0, 0, 21, 18};
        bodyPart.name = "Body";

        // Ajout de la partie du corps à la liste des parties du corps du serpent
        this->snakeSnd.push_back(bodyPart);
    }

    // Ajout de la première partie du corps du serpent à la liste des parties du corps
    this->snakeSnd.push_back(bodyPart1);
    // Générer de la nourriture et la placer sur la carte
    generateFood();
    
    // Assigner le serpent et la nourriture aux membres de la classe
    this->snake = snake;
    this->layer.push_back(snake);
    for (auto &part : snakeSnd)
        this->layer.push_back(part);
    this->layer.push_back(food);
    for (auto &innerVector : layer)
    {
        if (innerVector.name == "Food") {
            innerVector.x = food.x;
            innerVector.y = food.y;
        }
    }
}

std::vector<IObject> Snake::game_loop()
{
    this->timer++;

    if (this->timer % 2 == 0)
    {
        for (size_t i = snakeSnd.size() - 1; i > 0; --i)
        {
            snakeSnd[i].x = snakeSnd[i - 1].x;
            snakeSnd[i].y = snakeSnd[i - 1].y;
        }

        if (snakeSnd.size() > 0)
        {
            snakeSnd[0].x = snake.x;
            snakeSnd[0].y = snake.y;
        }

        

        switch (direction)
        {
        case UP:
            snake.y--;
            break;
        case DOWN:
            snake.y++;
            break;
        case LEFT:
            snake.x--;
            break;
        case RIGHT:
            snake.x++;
            break;
        default:
            break;
        }

        checkCollisionWithFood();
        checkCollision();
    }

    // checkCollision();

    layer.clear();
    layer.push_back(snake);
    layer.push_back(food);
    for (auto &innerVector : layer)
    {
        if (innerVector.name == "Food") {
            innerVector.x = food.x;
            innerVector.y = food.y;
            innerVector.name = "Food";
        }
    }

    for (auto &part : snakeSnd)
        layer.push_back(part);

    return layer;
}

void Snake::checkCollision()
{
    int headX = this->snake.x;
    int headY = this->snake.y;

    // murs
    if (headX <= 0 || headX >= map[0].size() - 1 || headY <= 0 || headY >= map.size() - 1)
    {
        gameover = true;
        return;
    }

    // corps
    for (size_t i = 1; i < layer.size(); ++i)
    {
        if (headX == layer[i].x && headY == layer[i].y)
        {
            gameover = true;
            return;
        }
    }
}

void Snake::generateFood()
{
    Food foodxy;
    int foodX = rand() % (map[0].size() - 2);
    if (foodX == 0)
        foodX = 1;
    if (foodX == map[0].size() - 1)
        foodX = map[0].size() - 2;
    int foodY = rand() % (map.size() - 2) + 1;
    if (foodY == 0)
        foodY = 1;
    if (foodY == map.size() - 1)
        foodY = map.size() - 2;

    foodxy.x = foodX;
    foodxy.y = foodY;
    foodxy.path = "./lib/graphicals/assets/snake/apple.png";
    foodxy.rect = {0, 0, 20, 20};
    food = foodxy;
}

void Snake::checkCollisionWithFood()
{
    int headX = snake.x;
    int headY = snake.y;

    if (headX == food.x && headY == food.y)
    {
        growSnake();
        add_score(10);
        for (auto &innerVector : layer)
        {
            if (innerVector.name == "Food") {
                generateFood();
                innerVector.x = food.x;
                innerVector.y = food.y;
                innerVector.rect = {0, 0, 20, 20};
                innerVector.name = "Food";
                innerVector.path = "./lib/graphicals/assets/snake/apple.png";
            }
        }
    }
}

void Snake::growSnake()
{
    ObjSnakeSnd &lastBodyPart = snakeSnd.back();

    ObjSnakeSnd newBodyPart;
    newBodyPart.x = lastBodyPart.x;
    newBodyPart.y = lastBodyPart.y - 1;
    newBodyPart.path = "./lib/graphicals/assets/snake/body.png";
    newBodyPart.name = "Body";
    newBodyPart.rect = {0, 0, 21, 18};

    snakeSnd.push_back(newBodyPart);
}

bool Snake::isSnakeBody(int x, int y)
{
    for (size_t i = 1; i < layer.size(); ++i)
    {
        if (x == layer[i].x && y == layer[i].y)
        {
            return true;
        }
    }
    return false;
}

void Snake::add_score(int score)
{
    this->score += score;
}

Snake::Snake()
{
    this->score = 0;
    srand(time(NULL));
    init_map();
}

Snake::~Snake() {}

void Snake::sendCommand(int moove)
{
    if (moove == UP && direction != DOWN)
        direction = UP;
    else if (moove == DOWN && direction != UP)
        direction = DOWN;
    else if (moove == LEFT && direction != RIGHT)
        direction = LEFT;
    else if (moove == RIGHT && direction != LEFT)
        direction = RIGHT;
}

std::vector<std::vector<std::string>> Snake::getStaticDecor() const
{
    return this->map;
}

std::vector<IObject> Snake::getObject()
{
    game_loop();
    return this->layer;
}

void Snake::setObject(std::vector<IObject> layer)
{
    this->layer = layer;
}

int Snake::getScore() const
{
    return this->score;
}

std::string Snake::getName() const
{
    return "Snake";
}

ObjSnake::ObjSnake()
{
    this->name = "Head";
}

ObjSnake::~ObjSnake() {}

ObjSnakeSnd::ObjSnakeSnd()
{
    this->name = "Body";
}

ObjSnakeSnd::~ObjSnakeSnd() {}

bool Snake::isGameOver() const
{
    return gameover;
}

Food::Food()
{
    this->name = "Food";
}

Food::~Food() {}

extern "C" IGamelib *instanceGame()
{
    return new Snake();
}
