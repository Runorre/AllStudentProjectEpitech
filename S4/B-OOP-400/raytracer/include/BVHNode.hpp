/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** BVHNode
*/

#pragma once
#include "main.hpp"
#include "Hitable.hpp"
#include "AABB.hpp"

class BVHNode {
    public:
        AABB box;
        std::shared_ptr<BVHNode> left;
        std::shared_ptr<BVHNode> right;
        std::vector<std::shared_ptr<Hitable>> primitives;
        bool hit(const Ray& r, double tMin, double tMax, hit_record& rec) const {
            if (!box.hit(r, tMin, tMax)) {
                return false;
            }

            bool hitLeft = left ? left->hit(r, tMin, tMax, rec) : false;
            bool hitRight = right ? right->hit(r, tMin, hitLeft ? rec.t : tMax, rec) : false;

            return hitLeft || hitRight;
        };
};