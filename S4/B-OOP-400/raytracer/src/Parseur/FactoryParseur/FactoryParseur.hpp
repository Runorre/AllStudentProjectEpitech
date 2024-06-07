/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_
#include "../../../include/RayTracer.hpp"
#include "../../../include/main.hpp"

class Factory {
    public:
        static std::shared_ptr<Hitable> factoryCreator(std::string type, libconfig::Setting &setting);
        
        static std::shared_ptr<Hitable> createSphere(libconfig::Setting &setting);
        static std::shared_ptr<Hitable> createCylinder(libconfig::Setting &setting);
        static std::shared_ptr<Hitable> createPlane(libconfig::Setting &setting);

    };

#endif /* !FACTORY_HPP_ */
