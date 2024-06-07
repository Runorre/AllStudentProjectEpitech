/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_
#include "IFruit.hpp"
#include <vector>
#include <ostream>

class FruitBox {
    public:
        FruitBox(unsigned int size);
        ~FruitBox();

        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *fruit);
        IFruit *popFruit();

        std::vector<IFruit *> getList() const;
    private:
        unsigned int _size_;
        std::vector<IFruit *> _array_;

};

std::ostream &operator<<(std::ostream &os, const FruitBox &f);

#endif /* !FRUITBOX_HPP_ */
