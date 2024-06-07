/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(ToyType type, std::string name, std::string fileName) {
    this->_name_ = name;
    this->_type_ = type;
    this->_ascii_ = new Picture(fileName);
}

Toy::Toy(const Toy &t) {
    this->_name_ = t.getName();
    this->_type_ = t.getType();
    this->_ascii_ = new Picture;
    this->_ascii_->data = t.getAscii();
}
Toy::Toy() {
    this->_type_ = BASIC_TOY;
    this->_name_ = "toy";
    this->_ascii_ = new Picture;
}

Toy &Toy::operator=(const Toy &source) {
    if (this != &source) {
        this->_name_ = source.getName();
        this->_type_ = source.getType();
        if (this->_ascii_)
            delete this->_ascii_;
        this->_ascii_ = new Picture;
        this->_ascii_->data = source.getAscii();
    }
    return *this;
}


Toy::~Toy() {
    delete this->_ascii_;
}

Toy::ToyType Toy::getType() const {
    return this->_type_;
}

std::string Toy::getName() const {
    return this->_name_;
}

void Toy::setName(std::string name) {
    this->_name_ = name;
}

bool Toy::setAscii(std::string fileName) {
    return this->_ascii_->getPictureFromFile(fileName);
}

std::string Toy::getAscii() const {
    return this->_ascii_->data;
}

void Toy::speak(std::string text) const {
    std::cout << this->_name_ << " \"" << text << "\"" << std::endl;
}
