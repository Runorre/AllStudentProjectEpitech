/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** clockwork
*/

#include "../../MyGKrellM.hpp"

#ifndef CLOCKWORK_HPP_
#define CLOCKWORK_HPP_

class Clockwork : public IModule {
    public:
        Clockwork();
        ~Clockwork();

        std::vector<std::map<std::string, std::string>> update();

    private:
        int _time;
        std::vector<std::map<std::string, std::string>> _clockwork;
};

#endif /* !CLOCKWORK_HPP_ */
