/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** RamInfo
*/

#include "../../MyGKrellM.hpp"

RamInfo::RamInfo() : _memInfo(1)
{
    this->openFile(this->_filePath);
    _memInfo[0]["MemMax"] = "0";
    _memInfo[0]["MemAvail"] = "0";
    this->parseFile();
}

RamInfo::~RamInfo()
{
}

bool RamInfo::parseFile() {
    std::string fileContent = this->getFileContent();
    std::string MemMax;
    std::istringstream input(fileContent);
    std::getline(input, MemMax);
    std::string MemAvail;
    std::getline(input, MemAvail);
    std::getline(input, MemAvail);

    _memInfo[0]["MemMax"] = MemMax.substr(MemMax.find_first_of("0123456789"), MemMax.find_last_of(" ") - MemMax.find_first_of("0123456789"));
    int MemMaxInt = std::stoi(_memInfo[0]["MemMax"]);

    int MemAvaInt = std::stoi(MemAvail.substr(MemAvail.find_first_of("0123456789"), MemAvail.find_last_of(" ") - MemAvail.find_first_of("0123456789")));
    _memInfo[0]["MemUse"] = std::to_string((MemMaxInt - MemAvaInt));
    return true;
}

std::vector<std::map<std::string, std::string>> RamInfo::update() {
    this->openFile(this->_filePath);
    this->parseFile();

    return this->_memInfo;
}
