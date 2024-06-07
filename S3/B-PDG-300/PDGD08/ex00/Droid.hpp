/*
** EPITECH PROJECT, 2024
** Day08
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_
#include <string>
#include <iostream>

class Droid {
    public:
        Droid(std::string serial = "");
        Droid(const Droid &d);
        ~Droid();

        size_t getAttack() const;
        size_t getToughness() const;
        std::string getId() const;
        size_t getEnergy() const;
        std::string getStatus() const;

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);

        void operator=(const Droid &source);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;
        void operator<<(size_t &reload);

    protected:
        const size_t _Attack = 25;
        const size_t _Toughness = 15;
    private:
        std::string _Id;
        size_t _Energy;
        std::string *_Status;

};

std::ostream &operator<<(std::ostream &os, const Droid &d);

#endif /* !DROID_HPP_ */
