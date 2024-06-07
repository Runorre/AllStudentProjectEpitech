/*
** EPITECH PROJECT, 2023
** B-OOP-400-MAR-4-1-raytracer-angelo.anselmet
** File description:
** LimitedCone.hpp
*/

#pragma once
#include "RayTracer.hpp"

class LimitedCone : public Hitable {
    public:
        LimitedCone() {};
        LimitedCone(Vector3D cen, double r, double h, std::shared_ptr<Material> m) : center(cen), radius(r), height(h), mat_ptr(m) {};
        bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;
        void setScale(double scale) { this->scale = scale; }
        Vector3D rotateX(double angle) const;
        Vector3D rotateY(double angle) const;
        Vector3D rotateZ(double angle) const;
        // bool boundingBox(double t0, double t1, AABB& outputBox) const;
    private:
        Vector3D center;
        double radius;
        double height;
        std::shared_ptr<Material> mat_ptr;
        double scale = 1.0;
};