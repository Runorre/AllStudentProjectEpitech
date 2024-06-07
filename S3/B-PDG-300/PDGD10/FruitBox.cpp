/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(unsigned int size) {
    this->_size_ = size;
}

FruitBox::~FruitBox() {
    for (unsigned int i = 0; i < this->_array_.size(); ++i) {
        delete this->_array_[i];
    }
    this->_array_.clear();
}

unsigned int FruitBox::getSize() const {
    return (this->_size_);
}

unsigned int FruitBox::nbFruits() const {
    return this->_array_.size();
}

bool FruitBox::pushFruit(IFruit *fruit) {
    if (this->_size_ == this->_array_.size())
        return false;
    for (unsigned int i = 0; i < this->_array_.size(); ++i) {
        IFruit* fruitTmp = this->_array_[i];
        if (fruitTmp == fruit)
            return true;
    }

    this->_array_.insert(this->_array_.end(), fruit);
    return true;
}

IFruit *FruitBox::popFruit() {
    if (this->_array_.empty())
        return nullptr;
    IFruit *first = this->_array_[0];
    this->_array_.erase(this->_array_.begin());
    return first;
}

std::vector<IFruit *> FruitBox::getList() const {
    return (this->_array_);
}

std::ostream &operator<<(std::ostream &os, const FruitBox &f) {
    std::vector<IFruit *> list = f.getList();
    os << "[";
    for (unsigned int i = 0; i < list.size(); ++i) {
        os << "[name: \"" << list[i]->getName() << "\", vitamins: " << list[i]->getVitamins() << ", peeled: " << std::boolalpha << list[i]->isPeeled() << "]";
        if ((i + 1) < list.size())
            os << ", ";
    }
    os << "]";
    return os;
}
