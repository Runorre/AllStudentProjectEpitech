/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Ray
*/
#pragma once
#include "Math.hpp"
class Ray {
    public:
        Ray() {}
        Ray(const Vector3D& a, const Vector3D b) {A = a; B = b;}
        Vector3D origin() const {return A;}
        Vector3D direction() const {return B;}
        Vector3D pointAtParameter(double t) const {return A + t * B;}

    private:
        Vector3D A;
        Vector3D B;
};
