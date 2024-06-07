/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_

#include "Hitable.hpp"

class Plane : public Hitable{
    public:
        Plane() {}
        Plane(std::string Axis, float Position, std::shared_ptr<Material> m) : Axis(Axis), Position(Position), mat_ptr(m) {};
        bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const;
        void setScale(double scale) { this->scale = scale; }
        void setxis(std::string newAxis) { this->Axis = newAxis; }
        void setPosition(float newPosition) { this->Position = newPosition; }
        // bool boundingBox(double t0, double t1, AABB& outputBox) const;
    protected:
    private:
        std::string Axis;
        float Position;
        std::shared_ptr<Material> mat_ptr;
        double scale = 1.0;
};

#endif /* !PLANE_HPP_ */
