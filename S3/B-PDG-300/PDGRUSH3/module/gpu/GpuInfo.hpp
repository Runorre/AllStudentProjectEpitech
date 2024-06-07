/*
** EPITECH PROJECT, 2024
** Rush 3
** File description:
** GPUInfo
*/

#ifndef GPUINFO_HPP_
#define GPUINFO_HPP_

#include "../../MyGKrellM.hpp"

class GpuInfo : public IModule {
    public:
        GpuInfo() {};
        ~GpuInfo() {};

        std::vector<std::map<std::string, std::string>> update() {
            std::vector<std::map<std::string, std::string>> rien;
            return rien;
        };
        bool parseFile() override {
            return false;
        };
        std::string getGpuInfo() const;

    protected:
    private:

};

#endif /* !GPUINFO_HPP_ */
