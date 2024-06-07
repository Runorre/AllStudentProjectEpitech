/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Camera
*/

#pragma once
#include "Ray.hpp"

class Camera {
    public:
        Camera(Vector3D lookfrom, Vector3D lookat, Vector3D vup, double vfov, double aspect, double aperture, double focusDist) {
            lens_radius = aperture / 2;
            double theta = vfov* M_PI / 180;
            double halfHeight = tan(theta/2);
            double halfWidth = aspect * halfHeight;
            origin = lookfrom;
            w = unit_vector(lookfrom - lookat);
            u = unit_vector(cross(vup, w));
            v = cross(w, u);
            lower_left_corner = origin - halfWidth * focusDist * u - halfHeight*focusDist*v - focusDist*w;
            horizontal = 2*halfWidth*u*focusDist;
            vertical = 2*halfHeight*v*focusDist;
        }

        Ray get_Ray(double s, double t) {
            Vector3D rd = lens_radius*randomInUnitDisk();
            Vector3D offset = u * rd.x() + v * rd.y();
            return Ray(origin + offset, lower_left_corner + s* horizontal + t * vertical - origin - offset);
        }

        Vector3D randomInUnitDisk() {
            Vector3D p;
            do {
                p = 2.0*Vector3D(drand48(),drand48(),0) - Vector3D(1,1,0);
            } while(dot(p,p) >= 1.0);
            return p;
        }
    private:
        
        Vector3D lower_left_corner, horizontal, vertical, origin;
        Vector3D u;
        Vector3D v;
        Vector3D w;
        double lens_radius;
};
