/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Axis aligned bounding box
*/

#pragma once
#include "Math.hpp"
#include "Ray.hpp"

class AABB {
public:

    AABB() {}
    AABB(const Vector3D& a, const Vector3D& b) : min_(a), max_(b) {}
    Vector3D min() const { return min_; }
    Vector3D max() const { return max_; }

    AABB unionBox(const AABB& other) const {
        Vector3D newMin(fmin(min_.x(), other.min().x()),
                        fmin(min_.y(), other.min().y()),
                        fmin(min_.z(), other.min().z()));
        Vector3D newMax(fmax(max_.x(), other.max().x()),
                        fmax(max_.y(), other.max().y()),
                        fmax(max_.z(), other.max().z()));
        return AABB(newMin, newMax);
    }

    int longestAxis() const {
        Vector3D extent = max_ - min_;
        if (extent.x() > extent.y() && extent.x() > extent.z()) {
            return 0;
        } else if (extent.y() > extent.z()) {
            return 1;
        } else {
            return 2;
        }
    }

    Vector3D center() const {
        return 0.5 * (min_ + max_);
    }

    bool hit(const Ray& r, double tmin, double tmax) const {
        for (int a = 0; a < 3; a++) {
            double invD = 1.0 / r.direction()[a];
            double t0 = (min()[a] - r.origin()[a]) * invD;
            double t1 = (max()[a] - r.origin()[a]) * invD;
            if (invD < 0.0) {
                std::swap(t0, t1);
            }
            tmin = t0 > tmin ? t0 : tmin;
            tmax = t1 < tmax ? t1 : tmax;
            if (tmax <= tmin) {
                return false;
            }
        }
        return true;
    }

private:
    Vector3D min_;
    Vector3D max_;
};
