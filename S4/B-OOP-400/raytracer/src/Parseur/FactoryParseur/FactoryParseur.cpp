/*
** EPITECH PROJECT, 2024
** Raytracer
** File description:
** Factory
*/

#include "FactoryParseur.hpp"

std::map<std::string, std::shared_ptr<Hitable> (*) (libconfig::Setting&)> factoryMap = {
    {"spheres", Factory::createSphere},
    // {"planes", Factory::createPlane}
};

std::shared_ptr<Hitable> Factory::factoryCreator(std::string type, libconfig::Setting &setting) {
    return factoryMap[type](setting);
}

// std::shared_ptr<Hitable> Factory::createPlane(libconfig::Setting &setting) {
//     if (!setting.exists("axis") || !setting.exists("position") || !setting.exists("color")) {
//         throw libconfig::SettingNotFoundException("Missing setting in configuration file section Plane.");
//     } if (!setting.exists("color") || setting["color"].getLength() != 3 || !setting["color"].exists("r") || !setting["color"].exists("g") || !setting["color"].exists("b"))
//         throw libconfig::SettingNotFoundException("Missing setting in configuration file section Plane-Color.");
    
//     std::string axis = setting["axis"];
//     double position = setting["position"];
//     int r = setting["color"]["r"];
//     int g = setting["color"]["g"];
//     int b = setting["color"]["b"];
//     Math::Vector3D color = Math::Vector3D(r, g, b);
//     return std::make_shared<RayTracer::Plane>(axis, position, color);
// }

std::shared_ptr<Hitable> Factory::createSphere(libconfig::Setting &setting) {
    if (!setting.exists("cen") || !setting.exists("r") || !setting.exists("mat")) {
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Sphere.");
    } if (!setting.exists("cen") || setting["cen"].getLength() != 3 || !setting["cen"].exists("x") || !setting["cen"].exists("y") || !setting["cen"].exists("z"))
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Sphere-Cen.");
    
    std::shared_ptr<Material> mat = FactoryMaterial::factoryMaterialCreator(setting["mat"][0].getName(), setting["mat"]);

    double x = setting["cen"]["x"];
    double y = setting["cen"]["y"];
    double z = setting["cen"]["z"];
    double r = setting["r"];
    Vector3D cen = Vector3D(x, y, z);
    return std::make_shared<Sphere>(cen, r, mat);
}

std::shared_ptr<Hitable> Factory::createCylinder(libconfig::Setting &setting) {
    if (!setting.exists("cen") || !setting.exists("r") || !setting.exists("mat") || !setting.exists("h")) {
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Cylinder.");
    } if (!setting.exists("cen") || setting["cen"].getLength() != 3 || !setting["cen"].exists("x") || !setting["cen"].exists("y") || !setting["cen"].exists("z"))
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Cylinder-Cen.");
    
    std::shared_ptr<Material> mat = FactoryMaterial::factoryMaterialCreator(setting["mat"][0].getName(), setting["mat"]);

    double x = setting["cen"]["x"];
    double y = setting["cen"]["y"];
    double z = setting["cen"]["z"];
    double r = setting["r"];
    double h = setting["h"];
    Vector3D cen = Vector3D(x, y, z);
    return std::make_shared<Cylinder>(cen, r, h, mat);
}

std::shared_ptr<Hitable> Factory::createPlane(libconfig::Setting &setting) {
    if (!setting.exists("axis") || !setting.exists("position") || !setting.exists("mat")) {
        throw libconfig::SettingNotFoundException("Missing setting in configuration file section Plane.");
    }
    
    std::shared_ptr<Material> mat = FactoryMaterial::factoryMaterialCreator(setting["mat"][0].getName(), setting["mat"]);

    std::string axis = setting["axis"];
    float position = setting["position"];
    return std::make_shared<Plane>(axis, position, mat);
}
