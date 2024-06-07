/*
** EPITECH PROJECT, 2024
** Day11
** File description:
** SafeDirectoryLister
*/

#ifndef SAFEDIRECTORYLISTER_HPP_
#define SAFEDIRECTORYLISTER_HPP_
#include <exception>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
    public:
        SafeDirectoryLister();
        SafeDirectoryLister(const std::string& path, bool hidden);

        ~SafeDirectoryLister();

        std::string get() const;
        bool open(const std::string& path, bool hidden);

    protected:
    private:
        DIR *stream;
        bool hidden;
};

#endif /* !SAFEDIRECTORYLISTER_HPP_ */
