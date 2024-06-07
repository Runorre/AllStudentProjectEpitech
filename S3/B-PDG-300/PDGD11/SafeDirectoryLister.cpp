/*
** EPITECH PROJECT, 2024
** Day11
** File description:
** SafeDirectoryLister
*/

#include "SafeDirectoryLister.hpp"

SafeDirectoryLister::SafeDirectoryLister() {
    this->stream = nullptr;
    this->hidden = false;
}

SafeDirectoryLister::SafeDirectoryLister(const std::string& path, bool hidden) {
    this->stream = opendir(path.c_str());
    this->hidden = hidden;
    if (!this->stream) {
        this->stream = nullptr;
        throw SafeDirectoryLister::OpenFailureException();
    }
}

SafeDirectoryLister::~SafeDirectoryLister() {
    if (this->stream != nullptr)
        closedir(this->stream);
}

bool SafeDirectoryLister::open(const std::string& path, bool hidden) {
    this->hidden = hidden;
    if (this->stream != nullptr)
        closedir(this->stream);
    this->stream = opendir(path.c_str());
    if (!this->stream) {
        this->stream = nullptr;
        throw SafeDirectoryLister::OpenFailureException();
    }
    return true;
}

std::string SafeDirectoryLister::get() const {
    if (this->stream != nullptr) {
        struct dirent* ent;
        ent = readdir(this->stream);
        while (!hidden && ent && ent->d_name[0] == '.') {
            ent = readdir(this->stream);
        }
        if (ent)
            return ent->d_name;
        else
            throw SafeDirectoryLister::NoMoreFileException();
    } else {
        throw SafeDirectoryLister::OpenFailureException();
    }
}
