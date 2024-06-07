/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** HitableList
*/

#include "../include/HitableList.hpp"

bool HitableList::hit(const Ray& r, double tMin, double tMax, hit_record& rec) const {
    hit_record temp_rec;
    bool hitAnything = false;
    double closestSoFar = tMax;
    for(int i = 0; i < list.size(); i++) {
        if (this->list[i]->hit(r, tMin, closestSoFar, temp_rec)){
            hitAnything = true;
            closestSoFar = temp_rec.t;
            rec=temp_rec;
        }
    }
    return hitAnything;
}


