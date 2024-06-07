/*
** EPITECH PROJECT, 2024
** Rush 3
** File description:
** RamInfo
*/

#ifndef RAMINFO_HPP_
#define RAMINFO_HPP_

#include "../../MyGKrellM.hpp"

class RamInfo : public IModule {
    public:
        RamInfo();
        ~RamInfo();

        std::vector<std::map<std::string, std::string>> update();
        bool parseFile() override;

    protected:
    private:
        std::vector<std::map<std::string, std::string>> _memInfo;
        std::string _filePath = "/proc/meminfo";
};

#endif /* !RAMINFO_HPP_ */
