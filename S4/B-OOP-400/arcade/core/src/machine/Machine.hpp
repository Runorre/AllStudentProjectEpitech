/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Machine
*/

#ifndef MACHINE_HPP_
    #define MACHINE_HPP_
    #include "../../include/coreArcade.hpp"
    #include <fstream>
    #include <sstream>
    #include <algorithm>
    #include <memory>
    #include <fstream>


    class Machine {
        public:
            Machine(std::string pathLib);
            ~Machine();

            void start_machine();
            void init_score();
            void save_score();

            void main_loop();

        protected:
        private:
            static void deleter(IGamelib* obj) { delete obj; };
            static void deleterGraph(IGraphlib* obj) { delete obj; };
            void* _libGrapMenu;
            std::vector<void*> _libGraps;
            std::vector<void*> _libGames;

            std::vector<IGraphlib* (*)()> _instancesGraphs;
            std::vector<IGamelib* (*)()> _instancesGames;

            std::vector<std::vector<std::string>> _allScore;

            bool _running;
    
            IGraphlib* _graph_menu;
            int _gameSelected;
            int _graphSelect;

            std::string _playerName;
            int _scoreCurrent;

            std::unique_ptr<IGamelib, decltype(&Machine::deleter)> gameInstance;
            std::unique_ptr<IGraphlib, decltype(&Machine::deleterGraph)> graphInstance;

            std::vector<std::string> _pathLibsGames;
            std::vector<std::string> _libsNameGames;
            std::vector<std::string> _pathLibsGraphs;
            std::vector<std::string> _libsNameGraphs;
    };

#endif /* !MACHINE_HPP_ */
