/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Machine
*/

#include "Machine.hpp"

Machine::Machine(std::string pathLib) : gameInstance(nullptr, &Machine::deleter), graphInstance(nullptr, &Machine::deleterGraph) {
    this->_libGrapMenu = dlopen(pathLib.c_str(), RTLD_LAZY);
    if (!this->_libGrapMenu) {
        std::cerr << "Cannot open library: " << dlerror() << std::endl;
        exit(84);
    }

    IGraphlib* (*instance)() = (IGraphlib* (*)()) dlsym(this->_libGrapMenu, "instanceGraph");
    if (!instance) {
        const std::string dlsym_errorA = dlerror();
        std::cerr << "Incompatible Lib: " << dlsym_errorA << '\n';
        dlclose(this->_libGrapMenu);
        exit(84);
    }

    this->_graph_menu = instance();
}

void Machine::init_score() {
    std::string line;
    std::ifstream file("./score");

    if (!file.is_open()) {
        this->_allScore = {};
        return;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        std::string score;
        if (!(iss >> name >> score)) { break; } // error

        this->_allScore.push_back({name, score});
    }

    file.close();

    std::sort(this->_allScore.begin(), this->_allScore.end(), [](const std::vector<std::string>& a, const std::vector<std::string>& b) {
        return std::stoi(a[1]) > std::stoi(b[1]);
    });
}

void Machine::start_machine() {

    for (const auto & entry : std::filesystem::directory_iterator("./lib")) {
        if (entry.path().extension() == ".so") {
            void *lib = dlopen(entry.path().string().c_str(), RTLD_LAZY);
            IGraphlib* (*instanceGraph)() = (IGraphlib* (*)()) dlsym(lib, "instanceGraph");

            if (!instanceGraph) {
                //If you are here, is not a GraphLib
                IGamelib* (*instanceGame)() = (IGamelib* (*)()) dlsym(lib, "instanceGame");

                if (!instanceGame) {
                    //If you are here, is not a Gamelib
                    std::cerr << entry.path().string().c_str() <<": Incompatible Lib: " << dlerror() << std::endl;
                } else {
                    std::string filename = entry.path().stem().string();
                    std::string prefix = "arcade_";
                    if (filename.substr(0, prefix.size()) == prefix) {
                        filename = filename.substr(prefix.size());
                    }
                    filename[0] = std::toupper(filename[0]);
                    this->_libGames.push_back(lib);
                    this->_instancesGames.push_back(instanceGame);
                    this->_pathLibsGames.push_back(entry.path().string().c_str());
                    this->_libsNameGames.push_back(filename);
                }
            } else {
                std::string filename = entry.path().stem().string();
                    std::string prefix = "arcade_";
                    if (filename.substr(0, prefix.size()) == prefix) {
                        filename = filename.substr(prefix.size());
                    }
                filename[0] = std::toupper(filename[0]);
                this->_libGraps.push_back(lib);
                this->_instancesGraphs.push_back(instanceGraph);
                this->_pathLibsGraphs.push_back(entry.path().string().c_str());
                this->_libsNameGraphs.push_back(filename);
            }
        }
    }
    this->init_score();
    this->_graph_menu->menu(this->_libsNameGraphs, this->_libsNameGames, this->_allScore);
    this->_gameSelected = this->_graph_menu->selectLibGame();
    this->_graphSelect = this->_graph_menu->selectLibGraphic();
    std::cout << this->_gameSelected << "" << this->_graphSelect << std::endl;
    if (_graphSelect == -1 || _gameSelected == -1) {
        exit(84);
    }
    this->_playerName = this->_graph_menu->getNamePlayer();
    this->_scoreCurrent = 0;
    this->_running = true;
    this->main_loop();
}

void Machine::save_score() {
    std::ofstream file("./score", std::ios::app);
    file << this->_playerName << " " << this->_scoreCurrent << std::endl;
    file.close();
}

void Machine::main_loop() {
    this->gameInstance.reset(this->_instancesGames[this->_gameSelected]());
    this->graphInstance.reset(this->_instancesGraphs[this->_graphSelect]());
    std::vector<std::vector<std::string>> staticMap = this->gameInstance->getStaticDecor();
    int hight = staticMap.size() * 20; // hauteur
    int width = staticMap[0].size() *20; // Largeur
    this->graphInstance->init_windows(hight, width);
    bool pause = false;
    
    KeyEvent keys = NONE;
    std::vector<IObject> assets = {};
    while (this->_running) {
        keys = this->graphInstance->handlekeyevent();
        if (pause == false) {
            if (keys != NONE) {
                if (keys == CLOSE) {
                    this->_running = false;
                    this->graphInstance->reset_windows();
                    break;
                } else if (keys == NEXTLIB) {
                    if ((this->_graphSelect + 1) == (int) this->_instancesGraphs.size())
                        this->_graphSelect = 0;
                    else
                        this->_graphSelect++;
                    this->graphInstance->reset_windows();
                    this->graphInstance.reset(this->_instancesGraphs[this->_graphSelect]());
                    this->graphInstance->init_windows(hight, width);
                    this->graphInstance->display();
                    this->graphInstance->clear();
                } else if (keys == NEXTGAME) {
                    if ((this->_gameSelected + 1) == (int) this->_instancesGames.size())
                        this->_gameSelected = 0;
                    else
                        this->_gameSelected++;
                    this->save_score();
                    this->graphInstance->reset_windows();
                    this->gameInstance.reset(this->_instancesGames[this->_gameSelected]());
                    staticMap = this->gameInstance->getStaticDecor();
                    hight = staticMap.size() * 20;
                    width = staticMap[0].size() *20;
                    this->graphInstance->init_windows(hight, width);
                    assets = {};
                    _scoreCurrent = 0;
                } else if (keys == PAUSE) {
                    pause = true;
                } else if (keys == RESET) {
                    this->gameInstance.reset(this->_instancesGames[this->_gameSelected]());
                    staticMap = this->gameInstance->getStaticDecor();
                    assets = {};
                    _scoreCurrent = 0;
                } else {
                    this->gameInstance->sendCommand(keys);
                }
            }
            if (this->gameInstance->isGameOver() == true) {
                this->_running = false;
                this->graphInstance->reset_windows();
                break;
            }
            if (pause == false) {
                this->graphInstance->showStaticbackground(staticMap);
                assets = this->gameInstance->getObject();
                _scoreCurrent = this->gameInstance->getScore();
                this->graphInstance->showDynamicAssets(assets);
                this->graphInstance->showScore(_scoreCurrent);
                this->graphInstance->display();
                this->graphInstance->clear();
            }
        } else {
            if (keys != NONE) {
                if (keys == CLOSE) {
                    this->_running = false;
                    this->graphInstance->reset_windows();
                    break;
                } else if (keys == PAUSE) {
                    pause = false;
                }
            }
            this->graphInstance->showStaticbackground(staticMap);
            this->graphInstance->showDynamicAssets(assets);
            this->graphInstance->showScore(_scoreCurrent);
            this->graphInstance->display();
            this->graphInstance->clear();
        }
        
    }
    this->save_score();
}

Machine::~Machine() {
    dlclose(this->_libGrapMenu);
    for (std::size_t i = 0; i < _libGames.size(); ++i) {
        dlclose(this->_libGames[i]);
    }
    for (std::size_t i = 0; i < _libGraps.size(); ++i) {
        dlclose(this->_libGraps[i]);
    }
}
