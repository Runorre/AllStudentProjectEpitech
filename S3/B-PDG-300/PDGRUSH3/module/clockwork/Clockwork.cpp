/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Clockwork
*/

#include "../../MyGKrellM.hpp"

Clockwork::Clockwork() : _clockwork(1) {
    this->_time = 0;
}

Clockwork::~Clockwork() {

}

std::vector<std::map<std::string, std::string>> Clockwork::update()
{
    time_t tempsActuel = time(0);


    tm *tempsLocal = localtime(&tempsActuel);

    _clockwork[0]["hour"] = std::to_string(tempsLocal->tm_hour);
    _clockwork[0]["min"] = std::to_string(tempsLocal->tm_min);
    _clockwork[0]["sec"] = std::to_string(tempsLocal->tm_sec);
    _clockwork[0]["day"] = std::to_string(tempsLocal->tm_mday);
    _clockwork[0]["mon"] = std::to_string((tempsLocal->tm_mon + 1));
    _clockwork[0]["year"] = std::to_string((tempsLocal->tm_year + 1900));

    return _clockwork;
}
