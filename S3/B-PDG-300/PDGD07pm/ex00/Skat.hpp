/*
** EPITECH PROJECT, 2024
** Day07PM
** File description:
** Skat
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_
#include <string>


class Skat
{
    public :
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        int &stimPaks();
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();
        
    private:
        int _stock;
        std::string _name;
};

#endif /* !SKAT_HPP_ */
