#pragma once
#include "hitable.h"

class sphere : public hitable {
public:
	vec3 center;
	float radius;
	material *mat_ptr = NULL;

	sphere() {}
	sphere(vec3 center, float radius) : center(center), radius(radius){}
	sphere(vec3 center, float radius, material *mat_ptr) : center(center), radius(radius), mat_ptr(mat_ptr) {}
	virtual bool hit(const ray &r, float t_min, float tMaX, hit_record &rec) const;
	virtual bool bounding_box(float t0, float t1, aabb &box) const;
};