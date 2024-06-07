/*
** EPITECH PROJECT, 2024
** Day08
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_
#include <string>

class DroidMemory {
    public:
        DroidMemory();
        size_t Fingerprint;
        size_t Exp;

        size_t getFingerprint() const;
        size_t getExp() const;

        void setFingerprint(size_t fingerprint);
        void setExp(size_t exp);

        void operator<<(DroidMemory &value);
        void operator>>(DroidMemory &value);

        void operator+=(DroidMemory &value);
        void operator+=(size_t value);

        DroidMemory operator+(DroidMemory &value) const;
        DroidMemory operator+(size_t value) const;
    protected:
    private:
        
};

std::ostream &operator<<(std::ostream &os, const DroidMemory &d);

#endif /* !DROIDMEMORY_HPP_ */
