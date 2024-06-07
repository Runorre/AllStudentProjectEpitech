/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman
*/

#include "pacman.hpp"
//28 31

void init_pacman(ObjPacman *pacman, ObjGhost *red, ObjGhost *pink, ObjGhost *blue, ObjGhost *orange)
{
    pacman->x = 15;
    pacman->y = 18;
    pacman->path = "./lib/graphicals/assets/pacman/pacman.png";
    pacman->coord = {37, 0};
    pacman->rect = {0, 0, 16, 15};

    red->x = 12;
    red->y = 14;
    red->path = "./lib/graphicals/assets/pacman/ghostred.png";
    red->basepath = "./lib/graphicals/assets/pacman/ghostred.png";
    red->coord = {78, 0};
    red->rect = {0, 0,20, 17};

    pink->x = 14;
    pink->y = 14;
    pink->path = "./lib/graphicals/assets/pacman/ghostpink.png";
    pink->basepath = "./lib/graphicals/assets/pacman/ghostpink.png";
    pink->coord = {78, 0};
    pink->rect = {0, 0,20, 17};

    blue->x = 12;
    blue->y = 15;
    blue->path = "./lib/graphicals/assets/pacman/ghostblue.png";
    blue->basepath = "./lib/graphicals/assets/pacman/ghostblue.png";
    blue->coord = {78, 0};
    blue->rect = {0, 0,20, 17};

    orange->x = 14;
    orange->y = 15;
    orange->path = "./lib/graphicals/assets/pacman/ghostyellow.png";
    orange->basepath = "./lib/graphicals/assets/pacman/ghostyellow.png";
    orange->coord = {78, 0};
    orange->rect = {0, 0,20, 17};
}

void Pacman::init_map()
{
     this->map = {
        {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}, //0
        {"1","2","2","2","2","2","2","2","2","2","2","2","2","1","2","2","2","2","2","2","2","2","2","2","2","2","1"}, //1
        {"1","2","1","1","1","1","2","1","1","1","1","1","2","1","2","1","1","1","1","1","2","1","1","1","1","2","1"}, //2 
        {"1","2","2","2","2","2","2","2","2","2","2","2","2","1","2","2","2","2","2","2","2","2","2","2","2","2","1"}, //3
        {"1","2","2","2","2","2","2","2","2","2","2","2","2","1","2","2","2","2","2","2","2","2","2","2","2","2","1"}, //4
        {"1","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","1"}, //5
        {"1","2","1","1","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","1","1","2","1"}, //6
        {"1","2","1","1","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","1","1","2","1"}, //7
        {"1","2","2","2","2","2","2","1","1","2","2","2","2","1","2","2","2","2","1","1","2","2","2","2","2","2","1"}, //8
        {"1","1","1","1","1","1","2","1","1","1","1","1","2","1","2","1","1","1","1","1","2","1","1","1","1","1","1"}, //9 //
        {"1","1","1","1","1","1","2","1","1","1","1","1","2","1","2","1","1","1","1","1","2","1","1","1","1","1","1"}, //10
        {"1","1","1","1","1","1","2","1","1","2","2","2","2","2","2","2","2","2","1","1","2","1","1","1","1","1","1"}, //11
        {"1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1"}, //12
        {"1","1","1","1","1","1","2","1","1","2","1","2","2","2","2","2","1","2","1","1","2","1","1","1","1","1","1"}, //13
        {"2","2","2","2","2","2","2","2","2","2","1","2","2","2","2","2","1","2","2","2","2","2","2","2","2","2","2"}, //14
        {"2","2","2","2","2","2","2","2","2","2","1","2","2","2","2","2","1","2","2","2","2","2","2","2","2","2","2"}, //15
        {"1","1","1","1","1","1","2","1","1","2","1","2","2","2","2","2","1","2","1","1","2","1","1","1","1","1","1"}, //16
        {"1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1"}, //17
        {"1","1","1","1","1","1","2","1","1","2","2","2","2","2","2","2","2","2","1","1","2","1","1","1","1","1","1"}, //18
        {"1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1"}, //19
        {"1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","1","1","1","1"}, //20 //
        {"1","2","2","2","2","2","2","2","2","2","2","2","2","1","2","2","2","2","2","2","2","2","2","2","2","2","1"}, //21
        {"1","2","1","1","1","1","2","1","1","1","1","1","2","1","2","1","1","1","1","1","2","1","1","1","1","2","1"}, //22
        {"1","2","1","1","1","1","2","1","1","1","1","1","2","1","2","1","1","1","1","1","2","1","1","1","1","2","1"}, //23
        {"1","2","2","2","1","1","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","1","1","2","2","2","1"}, //24
        {"1","1","1","2","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","2","1","1","1"}, //25
        {"1","1","1","2","1","1","2","1","1","2","1","1","1","1","1","1","1","2","1","1","2","1","1","2","1","1","1"}, //26
        {"1","2","2","2","2","2","2","1","1","2","2","2","2","1","2","2","2","2","1","1","2","2","2","2","2","2","1"}, //27
        {"1","2","1","1","1","1","1","1","1","1","1","1","2","1","2","1","1","1","1","1","1","1","1","1","1","2","1"}, //28
        {"1","2","1","1","1","1","1","1","1","1","1","1","2","1","2","1","1","1","1","1","1","1","1","1","1","2","1"}, //29
        {"1","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","2","1"}, //30
        {"1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"}  //31
    };  //0   1   2   3   4   5   6  7/   8   9  10  11  12  13  14  15  16  17  18  19/  20  21  22  23  24  25  26

    ObjPacman pacman;
    ObjGhost red;
    ObjGhost pink;
    ObjGhost blue;
    ObjGhost orange;
    init_pacman(&pacman, &red, &pink, &blue, &orange);
    
    this->pacman = pacman;
    this->ghosts.push_back(red);
    this->ghosts.push_back(pink);
    this->ghosts.push_back(blue);
    this->ghosts.push_back(orange);

    this->layer.push_back(pacman);
    this->layer.push_back(red);
    this->layer.push_back(pink);
    this->layer.push_back(blue);
    this->layer.push_back(orange);

    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 27; j++) {
            if (this->map[i][j] == "2" && ((i == 1 && j == 3) || (i == 30 && j == 3) || (i == 1 && j == 24) || (i == 30 && j == 24))) {
                Objgums gums;
                gums.x = j;
                gums.y = i;
                gums.path = "10";
                this->layer.push_back(gums);
                this->gums.push_back(gums);
            }
        }
    }
    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 26; j++) {
            if (this->map[i][j] == "2" && (((i < 9 || j < 7) && j != 0) || (i > 20 || j > 19))) {
                for (auto &gums : this->gums) {
                    if (!(gums.x == i && gums.y == j)) {
                        Objdot dot;
                        dot.x = j;
                        dot.y = i;
                        dot.path = "5";
                        this->layer.push_back(dot);
                        this->dots.push_back(dot);
                    }
                    else {
                        std::cout << gums.x << " " << gums.y << std::endl;
                    }
                }
            }
        }
    }
}

bool Pacman::isGameOver() const
{
    return gameover;
}

Pacman::~Pacman() {}

Pacman::Pacman()
{
    this->score = 0;
    init_map();
}

std::vector<std::vector<std::string>> Pacman::getStaticDecor() const
{
    return this->map;
}

std::vector<IObject> Pacman::getObject()
{
    this->layer = game_loop();
    return this->layer;
}

std::vector<Objdot> Pacman::getDots()
{
    return this->dots;
}

std::vector<Objgums> Pacman::getGums()
{
    return this->gums;
}

std::vector<ObjGhost> Pacman::getGhosts()
{
    return this->ghosts;
}

ObjPacman Pacman::getPacman()
{
    return this->pacman;
}

void Pacman::setObject(std::vector< IObject> layer)
{
    this->layer = layer;
}

void Pacman::sendCommand(int moove)
{
    // std::cout << moove << std::endl;
    
    if (this->direction != moove) {
        if (moove == UP) {
            pacman.rect = {0, 40, 16, 15};
            // if (this->map[std::floor(pacman.y - mov)][pacman.x] == "2")
            this->direction = UP;
        } else if (moove == DOWN) {
            pacman.rect = {0, 59, 16, 15};
            // if (this->map[std::round(pacman.y + mov + mov)][pacman.x] == "2")
            this->direction = DOWN;
        } else if (moove == LEFT) {
            pacman.rect = {0, 0, 16, 15};
            // if (this->map[pacman.y][std::floor(pacman.x - mov)] == "2")
            this->direction = LEFT;
        } else if (moove == RIGHT) {
            pacman.rect = {0, 20, 16, 15};
            this->direction = RIGHT;
        }
        
        // if (this->direction == UP) {
        //     if (this->map[std::ceil(pacman.y) - 1][pacman.x] == "2")
        //         pacman.y -= mov;
        // } else if (this->direction == DOWN) {
        //     if (this->map[pacman.y + 1][pacman.x] == "2")
        //         pacman.y += mov;
        // } else if (this->direction == LEFT) {
        //     if (this->map[pacman.y][std::ceil(pacman.x) - 1] == "2")
        //         pacman.x -= mov;
        // } else if (this->direction == RIGHT) {
        //     if (this->map[pacman.y][pacman.x + 1] == "2")
        //         pacman.x += mov;
        // }
        this->layer[0] = pacman;
    }
}

int Pacman::getScore() const
{
    return this->score;
}

void Pacman::add_score(int score)
{
    this->score += score;
}

std::string Pacman::getName() const
{
    return "pacman";
}

ObjPacman::ObjPacman()
{
    this->name = "pacman";
}

ObjPacman::~ObjPacman() {}

Objdot::Objdot()
{
    this->name = "dot";
}

Objdot::~Objdot() {}

Objgums::Objgums()
{
    this->name = "gums";
}

Objgums::~Objgums() {}

ObjGhost::ObjGhost()
{
    this->name = "ghost";
}

ObjGhost::~ObjGhost() {}
