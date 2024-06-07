/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** Cone
*/

#include "../include/Cone.hpp"

bool Cone::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    Vector3D oc = r.origin() - center;
    double k = (radius * scale) / (height * scale);
    double a = r.direction().x() * r.direction().x() + r.direction().z() * r.direction().z() - k * r.direction().y() * r.direction().y();
    double b = 2.0 * (oc.x() * r.direction().x() + oc.z() * r.direction().z() + k * k * r.direction().y());
    double c = oc.x() * oc.x() + oc.z() * oc.z() - k * oc.y() * oc.y();
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root = sqrt(discriminant);
        double temp = (-b - root) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            double y = rec.p.y();
            if (y < center.y() + height && y > center.y()) {
                rec.normal = (rec.p - center) / radius;
                rec.mat_ptr = mat_ptr;
                return true;
            }
        }
        temp = (-b + root) / (2.0 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.pointAtParameter(rec.t);
            double y = rec.p.y();
            if (y < center.y() + height && y > center.y()) {
                rec.normal = (rec.p - center) / radius;
                rec.mat_ptr = mat_ptr;
                return true;
            }
        }
    }
    return false;
}

Vector3D Cone::rotateX(double angle) const {
    return Vector3D(center.x(), center.y() * cos(angle) - center.z() * sin(angle), center.y() * sin(angle) + center.z() * cos(angle));
}

Vector3D Cone::rotateY(double angle) const {
    return Vector3D(center.x() * cos(angle) + center.z() * sin(angle), center.y(), -center.x() * sin(angle) + center.z() * cos(angle));
}

Vector3D Cone::rotateZ(double angle) const {
    return Vector3D(center.x() * cos(angle) - center.y() * sin(angle), center.x() * sin(angle) + center.y() * cos(angle), center.z());
}

// bool Cone::boundingBox(double t0, double t1, AABB& outputBox) const {
//     outputBox = AABB(center - Vector3D(radius, height, radius), center + Vector3D(radius, height, radius));
//     return true;
// }
