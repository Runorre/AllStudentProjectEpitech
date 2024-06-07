/*
** EPITECH PROJECT, 2024
** Day11
** File description:
** IDirectoryLister
*/

#ifndef IDIRECTORYLISTER_HPP_
#define IDIRECTORYLISTER_HPP_
#include <string>
#include <string.h>
#include <cstring>

class IDirectoryLister {
    public:
        virtual ~IDirectoryLister() = default;

        class OpenFailureException : public std::exception {
            public:
                ~OpenFailureException() override = default;
                const char* what() const noexcept override;
        };

        class NoMoreFileException : public std::exception {
            public:
                ~NoMoreFileException() override = default;
                const char* what() const noexcept override;
        };

        virtual bool open(const std::string &path, bool hidden) = 0;
        virtual std::string get() const = 0;
};

#endif /* !IDIRECTORYLISTER_HPP_ */
