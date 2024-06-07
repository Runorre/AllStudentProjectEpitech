/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** IModule
*/

#ifndef IMODULE_HPP_
#define IMODULE_HPP_

#include "../MyGKrellM.hpp"

// C'est la classe pour le module du moniteur

class IModule {
    public:
        IModule() = default;
        virtual ~IModule() = default;

        virtual std::vector<std::map<std::string, std::string>> update() = 0;

        bool openFile(std::string filePath);
        std::string getFileContent() const;
        virtual bool parseFile();
        std::string getParam(std::string str);
        std::string getValue(std::string str);
        std::string getValue2(std::string str);

    private:
        std::string _fileContent = "";
};

#endif /* !IMODULE_HPP_ */
