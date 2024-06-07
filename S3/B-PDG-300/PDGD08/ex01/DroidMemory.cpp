/*
** EPITECH PROJECT, 2024
** Day08
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"
#include <iostream>

DroidMemory::DroidMemory()
{
    this->Fingerprint = std::rand();
    this->Exp;
}

size_t DroidMemory::getFingerprint() const {
    return (this->Fingerprint);
}

size_t DroidMemory::getExp() const {
    return (this->Exp);
}

void DroidMemory::setFingerprint(size_t fingerprint) {
    this->Fingerprint = fingerprint;
}
void DroidMemory::setExp(size_t exp) {
    this->Exp = exp;
}

void DroidMemory::operator<<(DroidMemory &value) {
    this->Exp += value.Exp;
    value.Fingerprint ^= this->Fingerprint;
}

void DroidMemory::operator>>(DroidMemory &value) {
    value.Exp += this->Exp;
    this->Fingerprint ^= value.Fingerprint;
}

void DroidMemory::operator+=(DroidMemory &value) {
    this->Exp += value.Exp;
    value.Fingerprint ^= this->Fingerprint;
}

void DroidMemory::operator+=(size_t value) {
    this->Exp += value;
    this->Fingerprint ^= value;
}

DroidMemory DroidMemory::operator+(DroidMemory &value) const {
    DroidMemory result;
    result.Fingerprint = (this->Fingerprint ^ value.Fingerprint);
    result.Exp = (this->Exp + value.Exp);
    return result;
}

DroidMemory DroidMemory::operator+(size_t value) const {
    DroidMemory result;
    result.Fingerprint =(this->Fingerprint ^ value);
    result.Exp =(this->Exp + value);
    return result;
}

std::ostream &operator<<(std::ostream &os, const DroidMemory &d) {
    return os << "DroidMemory '" << d.getFingerprint() <<  "', " << d.getExp();
}
