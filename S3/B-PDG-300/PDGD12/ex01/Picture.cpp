/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Picture
*/

#include "Picture.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Picture::Picture() {
    this->data = "";
}

Picture::Picture(const std::string &file) {
    std::ifstream pict(file);

    if (!pict) {
        this->data = "ERROR";
        return;
    }
    std::ostringstream oss;
    oss << pict.rdbuf();
    this->data = oss.str();
    pict.close();
}

Picture::Picture(const Picture &p) {
    this->data = p.data;
}

Picture::~Picture() {}

bool Picture::getPictureFromFile(const std::string &file) {
    std::ifstream pict(file);

    if (!pict) {
        this->data = "ERROR";
        return false;
    }
    std::ostringstream oss;
    oss << pict.rdbuf();
    this->data = oss.str();
    pict.close();
    return true;
}

Picture &Picture::operator=(const Picture &source) {
    this->data = source.data;
    return *this;
}
