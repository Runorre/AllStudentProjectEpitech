/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-angelo.anselmet
** File description:
** LimitedCylinder.cpp
*/

#include "../include/LimitedCylinder.hpp"

bool LimitedCylinder::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    Vector3D oc = r.origin() - center;
    double a = r.direction().x() * r.direction().x() + r.direction().z() * r.direction().z();
    double b = 2.0 * (oc.x() * r.direction().x() + oc.z() * r.direction().z());
    double c = oc.x() * oc.x() + oc.z() * oc.z() - radius * radius * scale * scale;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root = sqrt(discriminant);
        double temp = (-b - root) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            double y = rec.p.y();
            if (y < center.y() + height && y > center.y()) {
                // Check if hit is not on the top or bottom surface
                if ((rec.p - center).squaredLength() <= radius * radius * scale * scale) {
                    rec.normal = (rec.p - center) / radius;
                    rec.mat_ptr = mat_ptr;
                    return true;
                }
            }
        }
        temp = (-b + root) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            double y = rec.p.y();
            if (y < center.y() + height && y > center.y()) {
                if ((rec.p - center).squaredLength() <= radius * radius * scale * scale) {
                    rec.normal = (rec.p - center) / radius;
                    rec.mat_ptr = mat_ptr;
                    return true;
                }
            }
        }
    }
    return false;
}


Vector3D LimitedCylinder::rotateX(double angle) const {
    return Vector3D(center.x(), center.y() * cos(angle) - center.z() * sin(angle), center.y() * sin(angle) + center.z() * cos(angle));
}

Vector3D LimitedCylinder::rotateY(double angle) const {
    return Vector3D(center.x() * cos(angle) + center.z() * sin(angle), center.y(), -center.x() * sin(angle) + center.z() * cos(angle));
}

Vector3D LimitedCylinder::rotateZ(double angle) const {
    return Vector3D(center.x() * cos(angle) - center.y() * sin(angle), center.x() * sin(angle) + center.y() * cos(angle), center.z());
}

// bool LimitedCylinder::boundingBox(double t0, double t1, AABB& outputBox) const {
//     outputBox = AABB(center - Vector3D(radius, height, radius), center + Vector3D(radius, height, radius));
//     return true;
// }