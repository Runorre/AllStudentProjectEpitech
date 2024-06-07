/*
** EPITECH PROJECT, 2024
** Day08
** File description:
** Droid
*/

#include "Droid.hpp"
#include <string>
#include <iostream>


Droid::Droid(std::string serial) {
    this->_Id = serial;
    this->_Energy = 50;
    this->_Status = new std::string("Standing by");
    this->BattleData = new DroidMemory;

    std::cout << "Droid '" << this->getId() << "' Activated" << std::endl; 
}

Droid::~Droid() {
    delete this->_Status;
    std::cout << "Droid '" << this->getId() << "' Destroyed" << std::endl;
}

void Droid::operator=(const Droid &source) {
    this->_Id = source.getId();
    this->_Energy = source.getEnergy();
    this->setStatus(new std::string(source.getStatus()));
}

Droid::Droid(const Droid &d) {
    this->_Id = d._Id;
    this->_Energy = d._Energy;
    this->_Status = new std::string(*d._Status);

    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

size_t Droid::getAttack() const {
    return (this->_Attack);
}

size_t Droid::getToughness() const {
    return (this->_Toughness);
}

std::string Droid::getId() const {
    return (this->_Id);
}

size_t Droid::getEnergy() const {
    return (this->_Energy);
}

std::string Droid::getStatus() const {
    return (*this->_Status);
}

void Droid::setId(std::string id) {
    this->_Id = id;
}

void Droid::setStatus(std::string *status) {
    delete this->_Status;
    this->_Status = status;
}

void Droid::setEnergy(size_t energy) {
    this->_Energy = energy;
}

bool Droid::operator==(const Droid &d) const {
    if (this->getStatus() == d.getStatus())
        return true;
    else
        return false;
}

bool Droid::operator!=(const Droid &d) const {
    if (this->getStatus() == d.getStatus())
        return false;
    else
        return true;
}

void Droid::operator<<(size_t &reload) {
    if ((this->_Energy + reload) > 100) {
        reload = (this->_Energy + reload) - 100;
        this->_Energy = 100;
    } else {
        this->_Energy += reload;
        reload = 0;
    }
    // if (reload <= (100 - this->_Energy)) {
    //     this->_Energy += reload;
    //     reload = 0;
    // }
    // else {
    //     reload -= (100 - this->_Energy);
    //     this->_Energy += (100 - this->_Energy);
    // }
}

DroidMemory *Droid::getBattleData() const {
    return (this->BattleData);
}

void Droid::setBattleData(DroidMemory *mem) {
    delete this->BattleData;
    this->BattleData = mem;
}

std::ostream &operator<<(std::ostream &os, const Droid &d) {
    return os << "Droid '" << d.getId() <<  "', " << d.getStatus() << ", " << d.getEnergy();
}
