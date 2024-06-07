/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** CurseDisplay
*/

#ifndef CURSE_DISPLAY_HPP
#define CURSE_DISPLAY_HPP

#include "../../MyGKrellM.hpp"

class Curse : public IDisplay {
public:
    Curse();
    ~Curse();
    void show() override;
    void changeModule(IModule* newModule) override;
    void changeAffichage(IModule* newModule) override;
    void afficherCarre(int starty, int startx, const std::string& content, int& squareHeight, const std::string title);
    void splitString(const std::string& input, char delimiter, std::vector<std::string>& output);
    std::string progressBar(double current, double max);
    std::string calculatePercentage(double current, double max);
private:
    CpuModule* cpuModule;
    IModule* ramModule;
    IModule* systemModule;
    IModule* clockModule;
    BatteryModule* batteryModule;
    
    std::string gpuData;

    std::vector<std::map<std::string, std::string>> _sysData;
    std::vector<std::map<std::string, std::string>> _cpuData;
    std::vector<std::map<std::string, std::string>> _ramData;
    std::vector<std::map<std::string, std::string>> _clockData;
};

#endif // CURSE_DISPLAY_HPP
