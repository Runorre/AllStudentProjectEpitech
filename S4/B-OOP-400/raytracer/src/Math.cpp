/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Math
*/

#include "../include/Math.hpp"

Vector3D reflect(const Vector3D& v, const Vector3D& n) {
    return v - 2 * dot(v, n) * n;
}

bool refract(const Vector3D& v, const Vector3D& n, double ni_over_nt, Vector3D& refracted) {
    Vector3D uv = unit_vector(v);
    double dt = dot(uv, n);
    double discriminant = 1.0 - ni_over_nt * ni_over_nt * (1 - dt * dt);
    if (discriminant > 0) {
        refracted = ni_over_nt * (uv - n * dt) - n * sqrt(discriminant);
        return true;
    }
    return false;
}
