/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** ErrorHandling
*/

#pragma once
class ErrorHandling {
    public:
        ErrorHandling(){};
        ~ErrorHandling(){};
        int checkArgs(int ac, char **av);
        int checkExtension(std::string filename);
    protected:
    private:
};
