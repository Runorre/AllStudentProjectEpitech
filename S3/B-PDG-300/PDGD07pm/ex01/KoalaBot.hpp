/*
** EPITECH PROJECT, 2024
** Day07PM
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_
#include <string>
#include "Parts.hpp"

class KoalaBot {
    public:
        KoalaBot(std::string serial = "Bob-01");

        void setParts(Arms &part);
        void setParts(Legs &part);
        void setParts(Head &part);

        void swapParts(Arms &part);
        void swapParts(Legs &part);
        void swapParts(Head &part);

        void informations();
        bool status();

    protected:
        std::string _serial;
    private:
        Arms _arms;
        Legs _legs;
        Head _head;

};

#endif /* !KOALABOT_HPP_ */
