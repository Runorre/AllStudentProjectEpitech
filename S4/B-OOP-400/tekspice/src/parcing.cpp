/*
** EPITECH PROJECT, 2024
** NanotekSpice
** File description:
** file
*/

#include "../include/nanotekspice.hpp"
#include "../include/IComponent.hpp"
#include <unordered_set>

// chipsetType != "input" && chipsetType != "output" && chipsetType != "xor" &&
//                             chipsetType != "or" && chipsetType != "and" && chipsetType != "not" &&
//                             chipsetType != "clock" && chipsetType != "4001" && chipsetType != "2716" &&
//                             chipsetType != "4008" && chipsetType != "4011" && chipsetType != "4013" &&
//                             chipsetType != "4017" && chipsetType != "4030" && chipsetType != "4040" &&
//                             chipsetType != "4069" && chipsetType != "4071" && chipsetType != "4081" &&
//                             chipsetType != "4094" && chipsetType != "4512" && chipsetType != "4514" &&
//                             chipsetType != "4801" && chipsetType != "true" && chipsetType != "false" &&
//                             chipsetType != "logger"

std::string removeSpaceLinks(const std::string& input) {
    std::string result = input;
    size_t colonPos = result.find(":");
    while (colonPos != std::string::npos) {
        size_t spaceAfter = colonPos + 1;
        while (spaceAfter < result.size() && result[spaceAfter] == ' ') {
            result.erase(spaceAfter, 1);
        }
        size_t spaceBefore = colonPos;
        while (spaceBefore > 0 && result[spaceBefore - 1] == ' ') {
            result.erase(spaceBefore - 1, 1);
            spaceBefore--;
        }
        colonPos = result.find(":", colonPos + 1);
    }
    return result;
}

std::string removeExtraSpaces(const std::string& str) 
{
    std::string result;
    result.reserve(str.size());
    bool inSpaces = true;
    for (char ch : str) {
        if (std::isspace(ch)) {
            if (!inSpaces) {
                result.push_back(' ');
                inSpaces = true;
            }
        } else {
            result.push_back(ch);
            inSpaces = false;
        }
    }
    if (!result.empty() && std::isspace(result.back())) {
        result.pop_back();
    }
    return result;
}
std::string removeComments(const std::string& str) 
{
    std::string result;
    bool commentFound = false;
    for (char ch : str) {
        if (ch == '#' && !commentFound) {
            commentFound = true;
            continue;
        }
        if (!commentFound) {
            result.push_back(ch);
        }
    }
    return result;
}

int parseFile(const char *filepath)
{
    std::vector<string> vChipsetComponent;
    std::vector<string> vChipsetName;
    std::vector<string> vLinkSrcName;
    std::vector<string> vLinkSrcPin;
    std::vector<string> vLinkDestName;
    std::vector<string> vLinkDestPin;

    bool chipsetsPresent = false;
    bool linksPresent = false;

    ifstream file(filepath);
    if (!file.is_open()) {
        cerr << "Can't open the file." << endl;
        throw nts::FileOpenFailed();
    }
    enum Section { None, Chipsets, Links };
    Section section = None;
    string line;
    std::unordered_set<std::string> seenNames;

    while (getline(file, line)) {
        line = removeComments(line);
        line = removeExtraSpaces(line);
        if (line.empty()) {
            continue;
        }
        if (line == ".chipsets:") {
            section = Chipsets;
            chipsetsPresent = true;
            continue;
        } else if (line == ".links:") {
            section = Links;
            linksPresent = true;
            continue;
        }
        switch (section) {
           case Chipsets:
                {
                    size_t pos = line.find(' ');
                    if (pos != std::string::npos) {
                        std::string chipsetName = line.substr(pos + 1);
                        std::string chipsetType = line.substr(0, pos);
                        if (seenNames.find(chipsetName) != seenNames.end()) {
                            throw nts::NameAlreadyUse();
                        }
                        //The ALED_ prefix use to say the componant is not finish
                        if (chipsetType != "input" && chipsetType != "output" && chipsetType != "xor" &&
                            chipsetType != "or" && chipsetType != "and" && chipsetType != "not" &&
                            chipsetType != "clock" && chipsetType != "4001" && chipsetType != "ALED_2716" &&
                            chipsetType != "4008" && chipsetType != "4011" && chipsetType != "4013" &&
                            chipsetType != "ALED_4017" && chipsetType != "4030" && chipsetType != "4040" &&
                            chipsetType != "4069" && chipsetType != "4071" && chipsetType != "4081" &&
                            chipsetType != "ALED_4094" && chipsetType != "ALED_4512" && chipsetType != "ALED_4514" &&
                            chipsetType != "ALED_4801" && chipsetType != "true" && chipsetType != "false" &&
                            chipsetType != "logger") {
                            throw nts::WrongTypeError(chipsetType);
                        }

                        vChipsetComponent.push_back(line.substr(0, pos));
                        vChipsetName.push_back(chipsetName);
                        seenNames.insert(chipsetName);
                    } else {
                        throw nts::MalformedLine();
                    }
                }

                break;
            case Links: 
                {
                    line = removeSpaceLinks(line);
                    size_t pos1 = line.find(':');
                    size_t pos2 = line.find(' ', pos1);
                    size_t pos3 = line.find(':', pos2);

                    if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos) {
                        vLinkSrcName.push_back(line.substr(0, pos1));
                        vLinkSrcPin.push_back(line.substr(pos1 + 1, pos2 - pos1 - 1));
                        vLinkDestName.push_back(line.substr(pos2 + 1, pos3 - pos2 - 1));
                        vLinkDestPin.push_back(line.substr(pos3 + 1));
                    } else {
                        throw nts::MalformedLine();
                    }
                }
                break;
            default:
                // throw nts::ParsingError(nts::ErrorType::UnknownError);
                break;
        }
       
    }
    if (vChipsetComponent.size() == 0 || vChipsetName.size() == 0 || vLinkSrcName.size() == 0 ||
        vLinkSrcPin.size() == 0 || vLinkDestName.size() == 0 || vLinkDestPin.size() == 0) {
            throw nts::EmptySection();
        }
    if (!chipsetsPresent || !linksPresent) {
        throw nts::MissingSection();
    }

    for (const auto& srcName : vLinkSrcName) {
        if (std::find(vChipsetName.begin(), vChipsetName.end(), srcName) == vChipsetName.end()) {
            throw nts::UnknownComponentError(srcName);
        }
    }
    for (const auto& destName : vLinkDestName) {
        if (std::find(vChipsetName.begin(), vChipsetName.end(), destName) == vChipsetName.end()) {
            throw nts::UnknownComponentError(destName);
        }
    }

    file.close();

    nts::Circuit mainCircuit(vChipsetName, vChipsetComponent);
    mainCircuit.createLinks(vLinkSrcName, vLinkSrcPin, vLinkDestName, vLinkDestPin);
    return mainActionNTS(&mainCircuit);


    // std::cout << "content : chipsets component:" << std::endl;
    // for (const auto& partie : vChipsetComponent) {
    //     std::cout << partie << std::endl;
    // }
    // std::cout << "content : chipsets name" << std::endl;
    // for (const auto& partie : vChipsetName) {
    //     std::cout << partie << std::endl;
    // }
    // std::cout << "Link Source Name: " << std::endl;
    // for (const auto& s : vLinkSrcName) {
    //     std::cout << s << std::endl;
    // }
    // std::cout << "Link Source Pin : " << std::endl;
    // for (const auto& s : vLinkSrcPin) {
    //     std::cout << s << std::endl;
    // }
    // std::cout << "Link Destination Name: " << std::endl;
    // for (const auto& d : vLinkDestName) {
    //     std::cout << d << std::endl;
    // }
    // std::cout << "Link Destination Pin : " << std::endl;
    // for (const auto& d : vLinkDestPin) {
    //     std::cout << d << std::endl;
    // } 
}
