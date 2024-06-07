/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Plane
*/

#include "../include/RayTracer.hpp"

bool Plane::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    float t;
    if (Axis == "x") {
        t = (Position - r.origin().x()) / r.direction().x();
    } else if (Axis == "y") {
        t = (Position - r.origin().y()) / r.direction().y();
    } else if (Axis == "z") {
        t = (Position - r.origin().z()) / r.direction().z();
    } else {
        return false;
    }

    if (t < t_min || t > t_max) {
        return false;
    }

    rec.t = t;
    rec.p = r.pointAtParameter(t);
    if (Axis == "x") {
        rec.normal = Vector3D(1, 0, 0);
    } else if (Axis == "y") {
        rec.normal = Vector3D(0, 1, 0);
    } else {
        rec.normal = Vector3D(0, 0, 1);
    }
    rec.mat_ptr = mat_ptr;
    return true;
}

// bool Plane::boundingBox(double t0, double t1, AABB& outputBox) const {
//     if (Axis == "x") {
//         outputBox = AABB(Vector3D(Position - 0.0001, -1000, -1000), Vector3D(Position + 0.0001, 1000, 1000));
//     } else if (Axis == "y") {
//         outputBox = AABB(Vector3D(-1000, Position - 0.0001, -1000), Vector3D(1000, Position + 0.0001, 1000));
//     } else {
//         outputBox = AABB(Vector3D(-1000, -1000, Position - 0.0001), Vector3D(1000, 1000, Position + 0.0001));
//     }
//     return true;
// }