/*
** EPITECH PROJECT, 2024
** B-PDG-300-MAR-3-1-PDGRUSH3-angelo.anselmet
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include "../MyGKrellM.hpp"

//C'est la classe pour créer un mode d'affichage du moniteur

class IDisplay {
    public:
        IDisplay() = default;
        virtual ~IDisplay() = default;

        //Elle c'est pour afficher le moniteur
        virtual void show() = 0;

        // Change le module actif et l'affichage actif (ligne 3 de la step 1)
        virtual void changeModule(IModule* newModule) = 0;
        virtual void changeAffichage(IModule* newModule) = 0;

    private:
        CpuModule cpu;
};

#endif /* !IDISPLAY_HPP_ */
