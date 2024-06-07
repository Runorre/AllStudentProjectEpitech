/*
** EPITECH PROJECT, 2024
** Day11
** File description:
** IDirectoryLister
*/

#include "IDirectoryLister.hpp"

const char* IDirectoryLister::OpenFailureException::what() const noexcept {
    return std::strerror(errno);
}

const char* IDirectoryLister::NoMoreFileException::what() const noexcept {
    return "End of stream";
}
