/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Sphere
*/

#include "../include/Sphere.hpp"

Sphere::Sphere()
{
}

bool Sphere::hit(const Ray& r, double t_min, double t_max, hit_record& rec) const {
    Vector3D oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = dot(oc, r.direction());
    double c = dot(oc, oc) - radius*radius*scale*scale;
    double discriminant = b*b - a*c;

	if (discriminant > 0) {
		double temp = (-b - sqrt(b * b - a * c)) / a;
		if(temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
		temp = (-b + sqrt(b * b - a * c)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.pointAtParameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
	}
	return false;
}

Vector3D Sphere::rotateX(double angle) const {
	return Vector3D(center.x(), center.y() * cos(angle) - center.z() * sin(angle), center.y() * sin(angle) + center.z() * cos(angle));
}

Vector3D Sphere::rotateY(double angle) const {
	return Vector3D(center.x() * cos(angle) + center.z() * sin(angle), center.y(), -center.x() * sin(angle) + center.z() * cos(angle));
}

Vector3D Sphere::rotateZ(double angle) const {
	return Vector3D(center.x() * cos(angle) - center.y() * sin(angle), center.x() * sin(angle) + center.y() * cos(angle), center.z());
}

// bool Sphere::boundingBox(double t0, double t1, AABB& outputBox) const {
// 	outputBox = AABB(center - Vector3D(radius, radius, radius), center + Vector3D(radius, radius, radius));
// 	return true;
// }
