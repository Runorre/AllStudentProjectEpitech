/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** HitableList
*/
#pragma once
#include "Hitable.hpp"

class HitableList: public Hitable {
    public:
        HitableList() {}
        HitableList(std::vector<std::shared_ptr<Hitable>> l, int n) {list = l; listSize = n;};
        bool hit(const Ray& r, double tMin, double tMax, hit_record& rec) const;
        std::vector<std::shared_ptr<Hitable>> list;
        int listSize;
};
