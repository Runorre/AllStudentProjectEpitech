/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
#define IFRUIT_HPP_
#include <string>
#include <iostream>

class IFruit {
    public:
        virtual ~IFruit() = default;

        virtual unsigned int getVitamins() const = 0;
        virtual std::string getName() const = 0;
        virtual bool isPeeled()const = 0;
        virtual void peel() = 0;

        bool operator==(const IFruit &other) const;

    protected:
    private:
};

std::ostream &operator<<(std::ostream &os, const IFruit &f);

#endif /* !IFRUIT_HPP_ */
