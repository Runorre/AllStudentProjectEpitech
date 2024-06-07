/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** FactoryMaterial
*/

#include "FactoryMaterial.hpp"

std::map<std::string, std::shared_ptr<Material> (*) (libconfig::Setting&)> factoryMatMap = {
    {"Dielectric", FactoryMaterial::createDielectric},
    {"Lambertian", FactoryMaterial::createLambertian},
    {"Metal", FactoryMaterial::createMetal}
};


std::shared_ptr<Material> FactoryMaterial::factoryMaterialCreator(std::string type, libconfig::Setting &setting) {
    if (factoryMatMap.find(type) == factoryMatMap.end())
        throw libconfig::SettingNotFoundException("Material type not found");
    return factoryMatMap[type](setting);
}

std::shared_ptr<Material> FactoryMaterial::createDielectric(libconfig::Setting &setting) {
    double refraction = setting["Dielectric"];
    return std::make_shared<Dielectric>(refraction);
}

std::shared_ptr<Material> FactoryMaterial::createLambertian(libconfig::Setting &setting) {
    if (!setting["Lambertian"].exists("r") || !setting["Lambertian"].exists("g") || !setting["Lambertian"].exists("b"))
        throw libconfig::SettingNotFoundException("Missing Lambertian values");
    int r = setting["Lambertian"]["r"];
    int g = setting["Lambertian"]["g"];
    int b = setting["Lambertian"]["b"];
    return std::make_shared<Lambertian>(Vector3D(r, g, b));
}

std::shared_ptr<Material> FactoryMaterial::createMetal(libconfig::Setting &setting) {
    if (!setting["Metal"].exists("vector") || !setting["Metal"]["vector"].exists("x") || !setting["Metal"]["vector"].exists("y") || !setting["Metal"]["vector"].exists("z") || !setting["Metal"].exists("f"))
        throw libconfig::SettingNotFoundException("Missing Metal values");
    double x = setting["Metal"]["vector"]["x"];
    double y = setting["Metal"]["vector"]["y"];
    double z = setting["Metal"]["vector"]["z"];
    double f = setting["Metal"]["f"];

    return std::make_shared<Metal>(Vector3D(x, y, z), f);
}


