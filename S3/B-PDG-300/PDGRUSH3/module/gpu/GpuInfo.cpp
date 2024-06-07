/*
** EPITECH PROJECT, 2024
** Rush 3
** File description:
** RamInfo
*/
#include "../../MyGKrellM.hpp"

std::string GpuInfo::getGpuInfo() const {
    std::string content;
    std::string command = "lspci | grep VGA";
    std::string mode = "r";
    FILE *fp = popen(command.c_str(), mode.c_str());
    char buffer[128];
    if (fp) {
        while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
            content += buffer;
            // if (content.find("c1:00.0 VGA compatible controller") != std::string::npos) {
            //     size_t pos = content.find("c1:00.0 VGA compatible controller");
            //     content = content.substr(pos, content.find('\n', pos));
            //     size_t infoStart = content.find(": ") + 2;
            //     content = content.substr(infoStart);
            //     break;
            // }
        }
        size_t infoStart = content.find(": ") + 2;
        if (infoStart != std::string::npos)
            content = content.substr(infoStart);
        pclose(fp);
    }
    return content;
}
