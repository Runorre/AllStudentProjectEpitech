/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** FactoryMaterial
*/

#ifndef FACTORYMATERIAL_HPP_
#define FACTORYMATERIAL_HPP_
#include "../../../include/RayTracer.hpp"
#include "../../../include/main.hpp"

class FactoryMaterial {
    public:
        static std::shared_ptr<Material> factoryMaterialCreator(std::string type, libconfig::Setting &setting);
        
        static std::shared_ptr<Material> createDielectric(libconfig::Setting &setting);
        static std::shared_ptr<Material> createLambertian(libconfig::Setting &setting);
        static std::shared_ptr<Material> createMetal(libconfig::Setting &setting);

    };

#endif /* !FACTORYMATERIAL_HPP_ */
