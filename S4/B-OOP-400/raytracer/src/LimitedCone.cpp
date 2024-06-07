/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-angelo.anselmet
** File description:
** LimitedCone.cpp
*/

#include "../include/LimitedCone.hpp"

bool LimitedCone::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    Vector3D oc = r.origin() - center;
    double a = r.direction().x() * r.direction().x() - r.direction().y() * r.direction().y() + r.direction().z() * r.direction().z();
    double b = 2.0 * (oc.x() * r.direction().x() - oc.y() * r.direction().y() + oc.z() * r.direction().z());
    double c = oc.x() * oc.x() - oc.y() * oc.y() + oc.z() * oc.z();
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root = sqrt(discriminant);
        double temp = (-b - root) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            double y = rec.p.y();
            if (y < center.y() + height && y > center.y()) {
                if ((rec.p - center).squaredLength() <= radius * radius * scale * scale) {
                    // Check if hit is above the cone base
                    if (rec.p.y() > center.y()) {
                        rec.normal = (rec.p - center) / radius;
                        rec.mat_ptr = mat_ptr;
                        return true;
                    }
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
                    if (rec.p.y() > center.y()) {
                        rec.normal = (rec.p - center) / radius;
                        rec.mat_ptr = mat_ptr;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
