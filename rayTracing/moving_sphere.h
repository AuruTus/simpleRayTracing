#pragma once
#include "hitable.h"

class moving_sphere : public hitable {
public:
	vec3 center0, center1;
	float time0, time1;
	float radius;
	material *mat_ptr;

	moving_sphere() {}
	moving_sphere(vec3 center0, vec3 center1, float t0, float t1, float r, material *m) :
		center0(center0), center1(center1), time0(t0), time1(t1), radius(r), mat_ptr(m) {}
	virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
	virtual bool bounding_box(float t0, float t1, aabb &box) const;
	vec3 center(float time) const;
};