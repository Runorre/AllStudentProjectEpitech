/*
** EPITECH PROJECT, 2024
** Day11
** File description:
** DirectoryLister
*/

#include "DirectoryLister.hpp"

DirectoryLister::DirectoryLister() {
    this->stream = nullptr;
    this->hidden = false;
}

DirectoryLister::DirectoryLister(const std::string& path, bool hidden) {
    this->stream = opendir(path.c_str());
    this->hidden = hidden;
    if (!this->stream) {
        perror(path.c_str());
        this->stream = nullptr;
    }
}

DirectoryLister::~DirectoryLister() {
    if (this->stream != nullptr)
        closedir(this->stream);
}

bool DirectoryLister::open(const std::string& path, bool hidden) {
    this->hidden = hidden;
    if (this->stream != nullptr)
        closedir(this->stream);
    this->stream = opendir(path.c_str());
    if (!this->stream) {
        perror(path.c_str());
        this->stream = nullptr;
        return false;
    }
    return true;
}

std::string DirectoryLister::get() const {
    if (this->stream != nullptr) {
        struct dirent* ent;
        ent = readdir(this->stream);
        while (!hidden && ent && ent->d_name[0] == '.') {
            ent = readdir(this->stream);
        }
        if (ent)
            return ent->d_name;
        else
            return ("");
    } else {
        return ("");
    }
}

