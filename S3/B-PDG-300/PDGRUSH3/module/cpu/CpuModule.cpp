/*
** EPITECH PROJECT, 2024
** Rush 3
** File description:
** CpuModule
*/

#include "../../MyGKrellM.hpp"

CpuModule::CpuModule()
{
    this->openFile(this->_filePathCPUInfo);
    this->parseFile();
    this->addCPUUsage();
}

CpuModule::~CpuModule()
{
}

void CpuModule::parseCore(std::vector<std::string> core)
{
    size_t i = 0;
    size_t size = core.size();
    std::string param;
    std::string value;
    std::map<std::string, std::string> currentMap;

    while (i < size) {
        param = this->getParam(core[i]);
        value = this->getValue(core[i]);
        currentMap[param] = value;
        i ++;
    }
    this->_coresVector.push_back(currentMap);
}

std::vector<std::map<std::string, std::string>> CpuModule::update()
{
    this->_coresVector.clear();
    this->openFile(this->_filePathCPUInfo);
    this->parseFile();
    this->addCPUUsage();
    return this->_coresVector;
}

void CpuModule::displayCores() const
{
    size_t i = 0;
    size_t size = this->_coresVector.size();

    std::cout << "MAIN CPU USAGE = " << this->_cpuUsage << std::endl;
    while (i < size) {
        std::cout << "CORE NUMERO i/size : " << i + 1 << "/" << size << std::endl;
        for(auto& x: this->_coresVector[i]){
            if (x.first == "usage") {
                std::cout << "PARAM->VALUE = " << "\"" << x.first << "\""
                    << " -> " << "\"" << x.second << "\"" << std::endl;
            }
        }
        std::cout << std::endl;
        i ++;
    }
}

bool CpuModule::parseFile()
{
    std::string fileContent = this->getFileContent();
    std::istringstream input(fileContent);
    std::vector<std::string> currentCore;
    std::string line;

    while (std::getline(input, line)) {
        if (line == "") {
            this->parseCore(currentCore);
            currentCore.clear();
        } else {
            currentCore.push_back(line);
        }
    }
    return true;
}

int CpuModule::getCPUNumber(std::string cpu)
{
    double num = -1;
    std::string numStr = "";
    int i = 3;

    if (cpu[i] == '\0' || cpu[i] == '\n' || cpu[i] == ' ')
        return num;
    while (cpu[i] != '\0' && cpu[i] != ' ') {
        numStr += cpu[i];
        i ++;
    }
    num = std::stod(numStr);
    return num;
}

static bool is_number(const std::string& s)
{
    return (strspn( s.c_str(), "-.0123456789" ) == s.size());
}

std::vector<int> CpuModule::getColumnsData(std::string cpu)
{
    std::vector<int> columns;
    size_t i = 0;
    std::string nstr;

    while (cpu[i] != '\0' && cpu[i] != ' ' && cpu[i] != '\n' && cpu[i] != '\t')
        i ++;
    i ++;
    while (cpu[i] != '\0' && columns.size() < 10) {
        nstr = "";
        while (cpu[i] != ' ' && cpu[i] != '\0') {
            nstr += cpu[i];
            i ++;
        }
        if (is_number(nstr) && nstr.length() > 0)
            columns.push_back(atoi(nstr.c_str()));
        i ++;
    }
    return columns;
}

double CpuModule::calcCPUUsage(std::vector<int> col)
{
    double usage = 0;
    double total = 0;
    double totalWoIdle;
    size_t i = 0, size = col.size();

    if (size < 7)
        return usage;
    while (i < 7) {
        total += col[i];
        i ++;
    }
    totalWoIdle = total - col[3];
    usage = (totalWoIdle / total) * 100;
    return usage;
}

void CpuModule::setCPUUsage(std::string cpu)
{
    std::vector<int> columns = this->getColumnsData(cpu);
    int cpuNumber = this->getCPUNumber(cpu);
    double usage = 0;
    std::stringstream usageStream;

    usage = this->calcCPUUsage(columns);
    if (cpuNumber == - 1) {
        this->_cpuUsage = usage;
    } else {
        usageStream.precision(3);
        usageStream << std::fixed;
        usageStream << usage;
        this->_coresVector[cpuNumber]["usage"] = usageStream.str();
    }
}

void CpuModule::addCPUUsage()
{
    this->openFile(this->_filePathCPUUsage);
    std::string file = this->getFileContent();
    std::istringstream input(file);
    std::string line;

    while (std::getline(input, line)) {
        if (line.find("cpu") != std::string::npos) {
            this->setCPUUsage(line);
        }
        else if (line.find("processes") != std::string::npos) {
            this->_nprocess = atoi(getValue2(line).c_str());
        }
        else if (line.find("procs_running") != std::string::npos) {
            this->_nprocessRunning = atoi(getValue2(line).c_str());
        }
        else if (line.find("procs_blocked") != std::string::npos) {
            this->_nprocessBlocked = atoi(getValue2(line).c_str());
        }
    }
}
