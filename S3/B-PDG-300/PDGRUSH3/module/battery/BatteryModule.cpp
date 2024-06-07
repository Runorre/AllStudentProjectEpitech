/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** BatteryModule
*/

#include "../../MyGKrellM.hpp"

BatteryModule::BatteryModule()
{
    this->update();
}

BatteryModule::~BatteryModule()
{
}

std::vector<std::map<std::string, std::string>> BatteryModule::update()
{
    std::vector<std::map<std::string, std::string>> rien;
    this->getBatteryPercentage();
    this->isInCharge();
    return rien;
}

bool BatteryModule::parseFile()
{
    return false;
}

void BatteryModule::getBatteryPercentage() {
    int batteryPercentage;
    this->_BatteryPercentage = 0;
    for (const auto& entry : std::filesystem::directory_iterator("/sys/class/power_supply/")) {
        if (entry.is_directory()) {
            std::string batteryFilePath = entry.path().string() + "/capacity";
            std::ifstream batteryFile(batteryFilePath);
            if (batteryFile) {
                batteryFile >> batteryPercentage;
                this->_BatteryPercentage = batteryPercentage;
            }
        }
    }
}

void BatteryModule::isInCharge()
{
    std::ifstream acFile("/sys/class/power_supply/ACAD/online");
    int acStatus;
    this->_inCharge = false;

    if (!acFile)
        return;
    acFile >> acStatus;
    this->_inCharge = (acStatus == 1);
}
