/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-raytracer-angelo.anselmet
** File description:
** Light
*/

#include "../include/Light.hpp"

Light::Light(libconfig::Setting &setting)
{
    if (!setting.exists("position") || !setting.exists("color") || !setting.exists("intensity"))
        throw libconfig::SettingNotFoundException("Light: missing parameters");
    if (setting["position"].getLength() != 3 || setting["color"].getLength() != 3)
        throw libconfig::SettingNotFoundException("Light: invalid parameters");
    if (!setting["position"].exists("x") || !setting["position"].exists("y") || !setting["position"].exists("z"))
        throw libconfig::SettingNotFoundException("Light: missing parameters");
    if (!setting["color"].exists("r") || !setting["color"].exists("g") || !setting["color"].exists("b"))
        throw libconfig::SettingNotFoundException("Light: missing parameters");
    
    double x = setting["position"]["x"];
    double y = setting["position"]["y"];
    double z = setting["position"]["z"];
    int r = setting["color"]["r"];
    int g = setting["color"]["g"];
    int b = setting["color"]["b"];
    double intensity = setting["intensity"];
    this->position = Vector3D(x, y, z);
    this->color = Vector3D(r, g, b);
    this->intensity = intensity;
}


