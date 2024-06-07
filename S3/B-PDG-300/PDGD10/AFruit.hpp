/*
** EPITECH PROJECT, 2024
** Day10
** File description:
** AFruit
*/

#ifndef AFRUIT_HPP_
#define AFRUIT_HPP_
#include "IFruit.hpp"

class AFruit : public IFruit {
    public:
        AFruit(std::string name, unsigned int vitamin, bool peel);
        ~AFruit();

        unsigned int getVitamins() const;
        std::string getName() const;
        bool isPeeled()const;
        void peel();

    protected:
    private:
        std::string _name_;
        unsigned int _vitamin_;
        bool _peel_;
};

#endif /* !AFRUIT_HPP_ */
