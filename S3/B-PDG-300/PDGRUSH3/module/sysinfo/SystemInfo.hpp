/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** SystemInfo
*/

#ifndef SYSTEMINFO_HPP_
#define SYSTEMINFO_HPP_

#include "../../MyGKrellM.hpp"
#include <sstream>

class SystemInfo : public IModule {
    public:
        SystemInfo();
        ~SystemInfo();
        std::string getOsName();
        std::string getKernel();
        std::string getUserName();
        std::string getComputerName();
        std::vector<std::map<std::string, std::string>> update();
        std::vector<std::map<std::string, std::string>> getSysInfo() {return this->_sysinfo;};

    protected:
    private:
        std::vector<std::map<std::string, std::string>> _sysinfo;
};

#endif /* !SYSTEMINFO_HPP_ */
