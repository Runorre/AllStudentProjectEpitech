/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** BatteryModule
*/

#ifndef BATTERYMODULE_HPP_
#define BATTERYMODULE_HPP_

#include "../../MyGKrellM.hpp"

class BatteryModule : public IModule {
    public:
        BatteryModule();
        ~BatteryModule();

        std::vector<std::map<std::string, std::string>> update();
        void isInCharge();
        void getBatteryPercentage();
        bool parseFile() override;

        bool _inCharge;
        double _BatteryPercentage;
    private:
        std::string _filePath;
};

#endif /* !BATTERYMODULE_HPP_ */
