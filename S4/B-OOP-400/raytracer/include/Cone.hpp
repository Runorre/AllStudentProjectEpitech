/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** Cone
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "Hitable.hpp"

class Cone: public Hitable {
    public:
        Cone() {};
        Cone(Vector3D cen, double r, double h, std::shared_ptr<Material> m) : center(cen), radius(r), height(h), mat_ptr(m) {};
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

#endif /* !CONE_HPP_ */
