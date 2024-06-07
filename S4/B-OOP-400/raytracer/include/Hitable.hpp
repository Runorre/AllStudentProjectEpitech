/*
** EPITECH PROJECT, 2024
** lastTry
** File description:
** Hitable
*/
#pragma once
#include "Ray.hpp"
#include "AABB.hpp"

class Material;

class hit_record {
	public:
		double t;
		Vector3D p;
		Vector3D normal;
		std::shared_ptr<Material> mat_ptr;
};

class Hitable {
public:
	virtual bool hit(const Ray& r, double t_min, double t_max, hit_record& rec) const = 0;
	// virtual bool boundingBox(double t0, double t1, AABB& outputBox) const = 0;
};
