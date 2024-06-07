/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-angelo.anselmet
** File description:
** game
*/

#include "pacman.hpp"

ObjGhost choose_random_dir(std::vector<std::vector<std::string>> map, ObjGhost *ghost)
{
    double mov = 0.5;

    int random = rand() % 4 + 1;
    if (ghost->GhostOutside == true) {
        if (ghost->direction == UP) {
            if (!(map[std::ceil(ghost->y) - 1][ghost->x] == "2")) {
                ghost->direction = static_cast<KeyEvent>(random);
            }
        } else if (ghost->direction == DOWN) {
            if (!(map[ghost->y + 1][ghost->x] == "2")) {
                ghost->direction = static_cast<KeyEvent>(random);
            }
        } else if (ghost->direction == LEFT) {
            if (!(map[ghost->y][std::ceil(ghost->x) - 1] == "2")) {
                ghost->direction = static_cast<KeyEvent>(random);
            }
        } else if (ghost->direction == RIGHT) {
            if (!(map[ghost->y][ghost->x + 1] == "2")){
                ghost->direction = static_cast<KeyEvent>(random);
            }
        } else {
            ghost->direction = static_cast<KeyEvent>(random);
        }
    }
    if (ghost->timer % 2 == 0 && ghost->GhostOutside == true) {
        if (ghost->direction == UP) {
            if (map[std::ceil(ghost->y) - 1][ghost->x] == "2")
                ghost->y -= mov;
        } else if (ghost->direction == DOWN) {
            if (map[ghost->y + 1][ghost->x] == "2")
                ghost->y += mov;
        } else if (ghost->direction == LEFT) {
            if (map[ghost->y][std::ceil(ghost->x) - 1] == "2")
                ghost->x -= mov;
        } else if (ghost->direction == RIGHT) {
            if (map[ghost->y][ghost->x + 1] == "2")
                ghost->x += mov;
        }
    }
    return *ghost;
}

void ghost_true(std::vector<ObjGhost> &ghost)
{
    for (auto &innerVector : ghost) {
        if (innerVector.GhostOutside == false) {
            innerVector.GhostOutside = true;
            innerVector.x = 13;
            innerVector.y = 11;
        }
    }
}

std::vector<IObject> Pacman::game_loop()
{
    this->timer++;
    double mov = 0.5;
    int i = 0;

    pacman.timer++;
    if (pacman.timer % 2 == 0) {
        if (this->direction == UP) {
            if (this->map[std::ceil(pacman.y) - 1][pacman.x] == "2")
                pacman.y -= mov;
        } else if (this->direction == DOWN) {
            if (this->map[pacman.y + 1][pacman.x] == "2")
                pacman.y += mov;
        } else if (this->direction == LEFT) {
            if (this->map[pacman.y][std::ceil(pacman.x) - 1] == "2")
                pacman.x -= mov;
        } else if (this->direction == RIGHT) {
            if (this->map[pacman.y][pacman.x + 1] == "2")
                pacman.x += mov;
        }
    }

    if (pacman.x < 1)
        pacman.x = 25;
    if (pacman.x >= 25.5)
        pacman.x = 2;


    for (auto &innerVector : ghosts) {
        innerVector = choose_random_dir(getStaticDecor(), &innerVector);
        layer[i+1] = innerVector;
        innerVector.timer++;
        if (innerVector.timer == 300) {
            ghost_true(ghosts);
        }
        if (innerVector.x < pacman.x + 0.5 && innerVector.x > pacman.x - 0.5 && innerVector.y < pacman.y + 0.5 && innerVector.y > pacman.y - 0.5 && innerVector.GhostEatable == false) {
            gameover = true;
            //std::cout << "GAME OVER" << std::endl;
        }
        else if (innerVector.x < pacman.x + 0.5 && innerVector.x > pacman.x - 0.5 && innerVector.y < pacman.y + 0.5 && innerVector.y > pacman.y - 0.5 && innerVector.GhostEatable == true) {
            add_score(200);
            innerVector.GhostOutside = false;
            innerVector.x = 14;
            innerVector.y = 14;
            innerVector.GhostEatable = false;
            innerVector.timer = 0;
        }
        i++;
    } i = 0;

    if (dots.size() == 0) {
        gameover = true;
        std::cout << "YOU WIN" << std::endl;
    }
    for (auto &innerVector : dots) {
        if (innerVector.x < pacman.x + 1 && innerVector.x > pacman.x - 1 && innerVector.y < pacman.y + 1 && innerVector.y > pacman.y - 1) {
            dots.erase(dots.begin() + i);
            add_score(10);
        }
        i++;
    } i = 0;

    for (auto &innerVector : gums) {
        if (innerVector.x < pacman.x + 1.5 && innerVector.x > pacman.x - 1.5 && innerVector.y < pacman.y + 1.5 && innerVector.y > pacman.y - 1.5) {
            gums.erase(gums.begin() + i);
            pacman.timer = 0;
            int j = 0;
            for (auto &innerVector : ghosts) {
                innerVector.path = "./lib/graphicals/assets/pacman/ghostdead.png";
                innerVector.GhostEatable = true;
                j++;
            }
        }
        i++;
    } i = 0;

    if (pacman.timer >= 300) {
        for (auto &innerVector : ghosts) {
            innerVector.path = innerVector.basepath;
            innerVector.GhostEatable = false;
            i++;
        }
    } i = 0;

    layer.clear();
    layer.push_back(pacman);
    for (auto &innerVector : dots) {
        layer.push_back(innerVector);
    }
    for (auto &innerVector : gums) {
        layer.push_back(innerVector);
    }
    for (auto &innerVector : ghosts) {
        layer.push_back(innerVector);
    }

    return layer;
}

extern "C" IGamelib *instanceGame()
{
    return new Pacman();
}
