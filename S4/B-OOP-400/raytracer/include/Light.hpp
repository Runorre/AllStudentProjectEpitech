/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** Cylinder
*/

#pragma once

#include "Hitable.hpp"
#include "main.hpp"

class Light {
    public:
        Vector3D position;
        Vector3D color;
        double intensity;

        Light(const Vector3D position, const Vector3D color, double intensity) : position(position), color(color), intensity(intensity) {}
        Light(libconfig::Setting &setting);
};
