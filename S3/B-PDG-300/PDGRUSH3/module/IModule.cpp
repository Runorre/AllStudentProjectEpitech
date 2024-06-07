/*
** EPITECH PROJECT, 2024
** Rush 3
** File description:
** IModule
*/

#include "../MyGKrellM.hpp"

bool IModule::openFile(std::string filePath)
{
    std::ifstream file(filePath, std::ifstream::in);
    char currentChar;

    this->_fileContent = "";
    if (!file)
        return false;
    while (file) {
        currentChar = file.get();
        if (file)
            this->_fileContent += currentChar;
    }
    file.close();
    return true;
}

std::string IModule::getFileContent() const
{
    return this->_fileContent;
}

bool IModule::parseFile()
{
    return false;
}

static void strip(std::string &str)
{
    if  (str.length() != 0) {
        auto w = std::string(" ") ;
        auto n = std::string("\n") ;
        auto r = std::string("\t") ;
        auto t = std::string("\r") ;
        auto v = std::string(1 ,str.front());
        while((v == w) || (v==t) || (v==r) || (v==n)) {
            str.erase(str.begin());
            v = std::string(1 ,str.front());
        }
        v = std::string(1 , str.back());
        while((v ==w) || (v==t) || (v==r) || (v==n)) {
            str.erase(str.end() - 1 );
            v = std::string(1 , str.back());
        }
    }
}

std::string IModule::getParam(std::string str)
{
    std::string param = "";
    int i = 0;

    while (str[i] != '\0' && str[i] != ':') {
        param += str[i];
        i ++;
    }
    strip(param);
    return param;
}

std::string IModule::getValue(std::string str)
{
    std::string value = "";
    int i = 0;

    while (str[i] != '\0' && str[i] != ':') {
        i ++;
    }
    if (str[i] == '\0')
        return value;
    i ++;
    while (str[i] != '\0') {
        value += str[i];
        i ++;
    }
    strip(value);
    return value;
}

std::string IModule::getValue2(std::string str)
{
    std::string value = "";
    int i = 0;

    while (str[i] != '\0' && str[i] != ' ') {
        i ++;
    }
    if (str[i] == '\0')
        return value;
    i ++;
    while (str[i] != '\0') {
        value += str[i];
        i ++;
    }
    strip(value);
    return value;
}
