/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Sphere
*/

#pragma once
#include "Hitable.hpp"

class Sphere: public Hitable {
    public:
        Sphere();
        Sphere(Vector3D cen, double r, std::shared_ptr<Material> m) : center(cen), radius(r), mat_ptr(m) {};
        bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;
        void setScale(double scale) { this->scale = scale; }
        Vector3D rotateX(double angle) const;
        Vector3D rotateY(double angle) const;
        Vector3D rotateZ(double angle) const;
        // bool boundingBox(double t0, double t1, AABB& outputBox) const;
    private:
        Vector3D center;
        double radius;
        std::shared_ptr<Material> mat_ptr;
        double scale = 1.0;
};
