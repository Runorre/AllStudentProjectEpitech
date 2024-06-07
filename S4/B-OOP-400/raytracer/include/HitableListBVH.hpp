/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** HitableList
*/
#pragma once
#include "Hitable.hpp"
#include "BVHNode.hpp"

class HitableListBVH : public Hitable {
    public:
        HitableListBVH() {}
        HitableListBVH(std::vector<std::shared_ptr<Hitable>> l, int n) : list(l), listSize(n) {
            root = buildBVHTree(list);
        }
        bool hit(const Ray& r, double tMin, double tMax, hit_record& rec) const override;
        bool boundingBox(double t0, double t1, AABB& outputBox) const override;
        AABB surroundingBox(const AABB& box0, const AABB& box1) const {
            Vector3D small(
                fmin(box0.min().x(), box1.min().x()),
                fmin(box0.min().y(), box1.min().y()),
                fmin(box0.min().z(), box1.min().z())
            );
            Vector3D big(
                fmax(box0.max().x(), box1.max().x()),
                fmax(box0.max().y(), box1.max().y()),
                fmax(box0.max().z(), box1.max().z())
            );
            return AABB(small, big);
        }

    private:
        std::shared_ptr<BVHNode> root;
        std::vector<std::shared_ptr<Hitable>> list;
        int listSize;

        std::shared_ptr<BVHNode> buildBVHTree(const std::vector<std::shared_ptr<Hitable>>& primitives) const;
};
