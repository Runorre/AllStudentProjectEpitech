/*
** EPITECH PROJECT, 2024
** Rush 3
** File description:
** CpuModule
*/

#ifndef CPUMODULE_HPP_
#define CPUMODULE_HPP_

#include "../../MyGKrellM.hpp"

class CpuModule : public IModule {
    public:
        CpuModule();
        ~CpuModule();

        std::vector<std::map<std::string, std::string>> update();

        bool parseFile() override;
        void parseCore(std::vector<std::string> core);
        void displayCores() const;
        void addCPUUsage();
        void setCPUUsage(std::string cpu);
        int getCPUNumber(std::string cpu);
        std::vector<int> getColumnsData(std::string cpu);
        double calcCPUUsage(std::vector<int> col);

        float getFreq() {
            size_t i = 0, size = this->_coresVector.size();
            float freq = 0;
            std::string tmp;

            while (i < size) {
                tmp = this->_coresVector[i]["cpu MHz"];
                freq += atof(tmp.c_str());
                i ++;
            }
            return freq;

        };

        size_t _nprocess = 0;
        size_t _nprocessRunning = 0;
        size_t _nprocessBlocked = 0;
        double _cpuUsage = 0;

        std::vector<std::map<std::string, std::string>> _coresVector;

        enum CPUCol {USER = 0, NICE, SYSTEM, IDLE, IOWAIT, IRQ, SOFTIRQ, STEAL, GUEST, GEST_NICE};
        size_t _nprocess = 0;
        size_t _nprocessRunning = 0;
        size_t _nprocessBlocked = 0;
        double _cpuUsage = 0;
    protected:
    private:
        std::string _filePathCPUInfo = "/proc/cpuinfo";
        std::string _filePathCPUUsage = "/proc/stat";
};

#endif /* !CPUMODULE_HPP_ */
