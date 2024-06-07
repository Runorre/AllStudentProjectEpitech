/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Arcade
*/

#ifndef ARCADE_HPP_
    #define ARCADE_HPP_
    #include <vector>
    #include <string>
    #include <map>
    #include <iostream>

    class IObject {
    public:
        virtual ~IObject() = default;
        std::string name;
        double x;
        double y;
        std::string path;
        std::vector<int>rect;
        std::vector<int>coord;
    };

    #include "./IGamelib/IGamelib.hpp"
    #include "./IGraphlib/IGraphlib.hpp"

#endif /* !ARCADE_HPP_ */
