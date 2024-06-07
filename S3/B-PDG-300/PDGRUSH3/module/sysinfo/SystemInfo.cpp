/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** SystemInfo
*/

#include "../../MyGKrellM.hpp"

SystemInfo::SystemInfo() : _sysinfo(1)
{
}

SystemInfo::~SystemInfo()
{

}

std::string SystemInfo::getKernel()
{
    if (this->openFile("/proc/version")) {
        std::stringstream string(this->getFileContent());
        std::string word;
        for (int i = 0; i != 3; i++, string >> word) {}
        return word;
    }
    return "";
}

std::string SystemInfo::getComputerName()
{
    if (this->openFile("/etc/hostname"))
        return this->getFileContent();
    return "";
}

std::string SystemInfo::getUserName()
{
    return getlogin();
}

std::vector<std::map<std::string, std::string>> SystemInfo::update()
{

    _sysinfo[0]["hostname"] = this->getComputerName();
    _sysinfo[0]["username"] = this->getUserName();
    _sysinfo[0]["kernel"] = this->getKernel();
    _sysinfo[0]["os"]  = this->getOsName();

    return _sysinfo;
}

std::string SystemInfo::getOsName()
{
    std::ifstream file("/etc/os-release");
    std::string line;
    while (std::getline(file, line)) {
        if (line.substr(0, 11) == "PRETTY_NAME") {
            std::size_t first = line.find_first_of("\"");
            std::size_t last = line.find_last_of("\"");
            if (first != std::string::npos && last != std::string::npos && first < last) {
                return line.substr(first + 1, last - first - 1);
            }
        }
    }
    return "";
}
