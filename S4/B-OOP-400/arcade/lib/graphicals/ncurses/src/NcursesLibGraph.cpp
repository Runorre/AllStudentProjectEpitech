/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesLibGraph
*/

#include "NcursesLibGraph.hpp"
#include <cstdlib>
#include <cstring>

void initializeWindow(int &height, int &width, int &start_y, int &start_x, WINDOW *&win) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
    curs_set(1); 
    refresh();
    height = 5;
    width = 20;
    start_y = (LINES - height) / 2;
    start_x = (COLS - width) / 2;
    win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
}

void printCentered(WINDOW *win, int y, const char *text) {
    mvwprintw(win, y, (getmaxx(win) - strlen(text)) / 2, text);
    wrefresh(win);
}

void createThreeBoxes() {
    int height, width;
    getmaxyx(stdscr, height, width);

    int boxWidth = width / 4; // Largeur réduite
    int boxHeight = height / 4; // Hauteur réduite

    // Création de la première boîte
    int leftStartY = 15;
    int leftStartX = 1;
    WINDOW *winLeft = newwin(boxHeight, boxWidth, leftStartY, leftStartX);
    box(winLeft, 0, 0);
    wrefresh(winLeft);

    // Création de la deuxième boîte
    int rightStartY = 15;
    int rightStartX = (width / 4) * 3 + 1; // Alignement à droite
    WINDOW *winRight = newwin(boxHeight, boxWidth, rightStartY, rightStartX);
    box(winRight, 0, 0);
    wrefresh(winRight);

    // Création de la troisième boîte
    int bottomStartY = (height / 4) * 3 - boxHeight / 5; // Un peu plus haut
    int bottomWidth = width - 3 - boxWidth * 2; // Largeur réduite
    int bottomStartX = (width - bottomWidth) / 2; // Centrage horizontal
    WINDOW *winBottom = newwin(boxHeight, bottomWidth, bottomStartY, bottomStartX);
    box(winBottom, 0, 0);
    wrefresh(winBottom);

    delwin(winLeft);
    delwin(winRight);
    delwin(winBottom);
}

void printOptions(const std::vector<std::string>& libgraphs, const std::vector<std::string>& libgames, const std::vector<std::vector<std::string>>& scores, int selectedOptionIndex) {
    int y_offsetOne = 17;
    int y_offsetSnd = 17;
    int y_offsetThird = 27  ;

    if (libgraphs.empty()) {
        mvprintw(y_offsetOne, 3, "Choose a graphical library:");
        y_offsetOne += 1;
    } else {
        for (size_t i = 0; i < libgraphs.size(); ++i) {
            if (i == selectedOptionIndex) {
                attron(A_REVERSE);
            }
            mvprintw(y_offsetOne, 3, "Choose a graphical library: %s", libgraphs[i].c_str());
            if (i == selectedOptionIndex) {
                attroff(A_REVERSE);
            }
            y_offsetOne += 1;
        }
    }

    if (libgames.empty()) {
        mvprintw(y_offsetSnd, 120, "Choose a game library:");
        y_offsetSnd += 1;
    } else {
        for (size_t i = 0; i < libgames.size(); ++i) {
            if (i + libgraphs.size() == selectedOptionIndex) {
                attron(A_REVERSE);
            }
            mvprintw(y_offsetSnd, 120, "Choose a game library: %s", libgames[i].c_str());
            if (i + libgraphs.size() == selectedOptionIndex) {
                attroff(A_REVERSE);
            }
            y_offsetSnd += 1;
        }
    }
    if (scores.empty()) {
    mvprintw(y_offsetThird, 70, "Score:");
    y_offsetThird += 1;
    } else {
        size_t scoreCount = 0;
        for (size_t i = 0; i < scores.size(); ++i) {
            for (size_t j = 0; j < scores[i].size(); j += 2) {
                if (y_offsetThird == selectedOptionIndex) {
                    attron(A_REVERSE);
                }
                mvprintw(y_offsetThird, 70, "Score: %s %s", scores[i][j].c_str(), scores[i][j + 1].c_str());
                if (y_offsetThird == selectedOptionIndex) {
                    attroff(A_REVERSE);
                }
                y_offsetThird += 1;
                scoreCount++;
                if (scoreCount >= 5)
                    return;
            }
        }
    }

    refresh();
}

void NcursesLibGraph::determineSelectedLibraryAndGame(int x, int y, const std::vector<std::string> libgraphs, const std::vector<std::string> libgames) {
    int baseY = 17;
    for (size_t a = 0; a < libgraphs.size(); a++ ) {
        if (x >= 3 && x <= 34 && y == baseY + a)
            graphical = a;
    }

    for (size_t a = 0; a < libgames.size(); a++ ) {
        if (x >= 120 && x <= 148 && y == baseY + a)
            game = a;
    }
}

void NcursesLibGraph::handleSelectionAndName(int& selectedOptionIndex, int maxY, std::string& playerName, int height, int width, int start_y, int start_x, WINDOW* win, const std::vector<std::string>& libgraphs, const std::vector<std::string>& libgames, const std::vector<std::vector<std::string>>& scores) {
    mousemask(ALL_MOUSE_EVENTS, NULL);
    MEVENT event;
    char name[width - 4];
    // std::string selectedLibrary;
    // std::string selectedGame;
    // std::string lastSelectedLibrary;
    // std::string lastSelectedGame;
    bool gameStarted = false;
    while (!gameStarted) {
        int ch = getch();
        if (ch == KEY_MOUSE) {
            if (getmouse(&event) == OK) {
                determineSelectedLibraryAndGame(event.x, event.y, libgraphs, libgames);
                // mvprintw(1, 0, "Selected Library: %s", selectedLibrary.c_str());
                // mvprintw(2, 0, "Selected Game: %s", selectedGame.c_str());
                refresh();

                if (graphical != -1 && game != -1) {
                    mvprintw(5, 5, "START");
                    refresh();
                    if (event.y == 5 && event.x >= 5 && event.x <= 10) {
                        std::cout << "Game started" << std::endl;
                        gameStarted = true;
                        // lastSelectedLibrary = selectedLibrary;
                        // lastSelectedGame = selectedGame;
                    }
                }
                if (event.y >= start_y && event.y < start_y + height &&
                    event.x >= start_x && event.x < start_x + width) {
                    werase(win);
                    box(win, 0, 0);  
                    wrefresh(win);
                    curs_set(1);
                    echo(); 
                    mvwgetnstr(win, 2, 2, name, width - 4); 
                    noecho(); 
                    curs_set(0); 
                    playerName = name;
                    this->username = playerName;
                    wrefresh(win);
                    mvwprintw(win, 2, 2, "                 ");
                    wrefresh(win);
                    mvwprintw(win, height / 2, (width - strlen(name)) / 2, name);
                    wrefresh(win);
                } else if (event.y >= 17 && event.y < 17 + libgraphs.size() && event.x >= 3 && event.x < 15 + width) {
                    selectedOptionIndex = event.y - 17;
                    printOptions(libgraphs, libgames, scores, selectedOptionIndex);
                    refresh();
                } else if (event.y >= 14 + libgraphs.size() && event.y < 14 + libgraphs.size() + libgames.size() && event.x >= 120 && event.x < 130 + width) {
                    selectedOptionIndex = event.y - 14 - libgraphs.size();
                    printOptions(libgraphs, libgames, scores, selectedOptionIndex + libgraphs.size());
                    refresh();
                } else if (event.y >= 28 + libgraphs.size() + libgames.size() && event.y < 28 + libgraphs.size() + libgames.size() + scores.size() && event.x >= 77 && event.x < 77 + width) {
                    selectedOptionIndex = event.y - 28 - libgraphs.size() - libgames.size();
                    printOptions(libgraphs, libgames, scores, selectedOptionIndex + libgraphs.size() + libgames.size());
                    refresh();
                }
            }
        } else if (ch == 'q')
            break;
    }
    if (gameStarted) {
        // for (int i = 0; i < libgraphs.size(); i++) {
        //     if (lastSelectedLibrary == libgraphs[i]) {
        //         graphical = i;
        //     }
        // }
        // for (int i = 0; i < libgames.size(); i++) {
        //     if (lastSelectedGame == libgames[i]) {
        //         game = i;
        //     }
        // }
        delwin(win);
        endwin();
        return;
    }
    return;
}

void NcursesLibGraph::menu(std::vector<std::string> libgraphs, std::vector<std::string> libgames, std::vector<std::vector<std::string>> scores) {

    int height, width, start_y, start_x;
    WINDOW *win;
    initializeWindow(height, width, start_y, start_x, win);
    createThreeBoxes();
    int selectedOptionIndex = 0;
    std::string playerName;
    printOptions(libgraphs, libgames, scores, selectedOptionIndex);
    refresh();
    printCentered(win, height / 2, "NAME");
    handleSelectionAndName(selectedOptionIndex, height + 2, playerName, height, width, start_y, start_x, win, libgraphs, libgames, scores);
    return;
}

int NcursesLibGraph::selectLibGraphic() {
    return this->graphical;
}

int NcursesLibGraph::selectLibGame() {
    return this->game;
}

void NcursesLibGraph::init_windows(int height, int widght)
{
    initscr();
    noecho();
    curs_set(0);
    cbreak();
}

void NcursesLibGraph::reset_windows()
{
    endwin();
}

std::string NcursesLibGraph::getNamePlayer() {
    return username;
}

KeyEvent NcursesLibGraph::handlekeyevent() {
        nodelay(stdscr, TRUE);
        int ch = getch();
        if (ch == KEY_UP || ch == 'z' || ch == 'Z') {
            return UP;
        } else if (ch == KEY_DOWN || ch == 's' || ch == 'S') {
            return DOWN;
        } else if (ch == KEY_LEFT || ch == 'q' || ch == 'Q') {
            return LEFT;
        } else if (ch == KEY_RIGHT || ch == 'd' || ch == 'D') {
            return RIGHT;
        } else if (ch == KEY_BACKSPACE) {
            return CONFIRM;
        } else if (ch == ' ')
            return PAUSE;
        else if (ch == 'm' || ch == 'M')
            return NEXTLIB;
        else if (ch == 'n' || ch == 'N')
            return NEXTGAME;
        else if (ch == 'r' || ch == 'R')
            return RESET;
        else
            return NONE;
}

void NcursesLibGraph::showStaticbackground(std::vector<std::vector<std::string>> mapdecor)
{
    for (long unsigned int i = 0; i < mapdecor.size(); i++) {
        for (long unsigned int j = 0; j < mapdecor[i].size(); j++) {
            if (mapdecor[i][j] == "1") {
                mvprintw(i, j, "#");
            } else if (mapdecor[i][j] == "2") {
                mvprintw(i, j, " ");
            }
        }
    }
}


void NcursesLibGraph::showDynamicAssets(std::vector<IObject> assets) 
{
    for (long unsigned int i = 0; i < assets.size(); i++) {
        if (assets[i].name == "gums")
            mvprintw(assets[i].y, assets[i].x, "o");
        else if (assets[i].name == "Food")
            mvprintw(assets[i].y, assets[i].x, "F");
        else if (assets[i].name == "pacman")
            mvprintw(assets[i].y, assets[i].x, "C");
        else if (assets[i].name == "ghost")
            mvprintw(assets[i].y, assets[i].x, "A");
        else if (assets[i].name == "dot")
            mvprintw(assets[i].y, assets[i].x, ".");
        else if (assets[i].name == "Snake")
            mvprintw(assets[i].y, assets[i].x, "S");
        else if (assets[i].name == "Body")
            mvprintw(assets[i].y, assets[i].x, "s");
    }
}

void NcursesLibGraph::showScore(int score)
{
    mvprintw(0, 0, "Score: %d", score);
}

void NcursesLibGraph::display()
{
    refresh();
}

void NcursesLibGraph::clear()
{
    napms(33);
    // clear();
}

NcursesLibGraph::~NcursesLibGraph() {}

extern "C" IGraphlib* instanceGraph() {
    return new NcursesLibGraph();
}
