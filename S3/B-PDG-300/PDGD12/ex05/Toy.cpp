/*
** EPITECH PROJECT, 2024
** Day12
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(Toy::ToyType type, std::string name, std::string fileName) {
    this->_name_ = name;
    this->_type_ = type;
    this->_ascii_ = new Picture(fileName);
    this->err = new Toy::Error("", Toy::Error::UNKNOWN, "");
}

Toy::Toy(const Toy &t) {
    this->_name_ = t.getName();
    this->_type_ = t.getType();
        this->_ascii_ = new Picture;
    this->_ascii_->data = t.getAscii();
    this->err = new Toy::Error("", Toy::Error::UNKNOWN, "");
}

Toy::Toy() {
    this->_type_ = BASIC_TOY;
    this->_name_ = "toy";
    this->_ascii_ = new Picture;
    this->err = new Toy::Error("", Toy::Error::UNKNOWN, "");
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
    delete this->err;
}

Toy::ToyType Toy::getType() const {
    return this->_type_;
}

Toy &Toy::operator<<(const std::string &ascii) {
    this->_ascii_->data = ascii;
    return *this;
}

std::string Toy::getName() const {
    return this->_name_;
}

void Toy::setName(std::string name) {
    this->_name_ = name;
}

bool Toy::setAscii(std::string fileName) {
    bool result = this->_ascii_->getPictureFromFile(fileName);

    if (!result) {
        delete this->err;
        this->err = new Toy::Error("bad new illustration", Toy::Error::PICTURE, "setAscii");
    }

    return result;
}

std::string Toy::getAscii() const {
    return this->_ascii_->data;
}

void Toy::speak(std::string text) const {
    std::cout << this->_name_ << " \"" << text << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Toy &t) {
    return os << t.getName() << std::endl << t.getAscii() << std::endl;
}

Toy::Error::Error(std::string msg, Error::ErrorType type, std::string whereErr) {
    this->msgError = msg;
    this->type = type;
    this->whereError = whereErr;
}

const std::string Toy::Error::what() {
    return this->msgError;
}

const std::string Toy::Error::where() {
    return this->whereError;
}

bool Toy::speak_es(std::string text) {
    (void)text;
    delete this->err;
    this->err = new Toy::Error("wrong mode", Toy::Error::SPEAK, "speak_es");
    return false;
}

Toy::Error Toy::getLastError() const {
    return *this->err;
}
