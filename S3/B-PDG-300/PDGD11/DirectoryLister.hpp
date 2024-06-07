/*
** EPITECH PROJECT, 2024
** Day11
** File description:
** DirectoryLister
*/

#ifndef DIRECTORYLISTER_HPP_
#define DIRECTORYLISTER_HPP_
#include "IDirectoryLister.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <errno.h>

class DirectoryLister : public IDirectoryLister {
    public:
        DirectoryLister();
        DirectoryLister(const std::string& path, bool hidden);

        ~DirectoryLister();

        std::string get() const;
        bool open(const std::string& path, bool hidden);

    protected:
    private:
        DIR *stream;
        bool hidden;
};

#endif /* !DIRECTORYLISTER_HPP_ */
