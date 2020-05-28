#include "moving_sphere.h"

vec3 moving_sphere::center(float time) const {
	return center0 + ((time - time0) / (time1 - time0)) * (center1 - center0);
}

bool moving_sphere::hit(const ray &r, float t_min, float t_max, hit_record & rec) const {
	vec3 oc = r.origin() - center(r.time());
	float a = r.direction() % r.direction();
	float b = oc % r.direction();
	float c = oc % oc - radius * radius;
	float discriminant = b * b - a * c;
	if (discriminant > 0) {
		float temp = (-b - sqrt(discriminant)) / a;
		if (temp > t_min && temp < t_max) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center(r.time())) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
		temp = (-b + sqrt(discriminant)) / a;
		if (temp > t_min && temp < t_max) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center(r.time())) / radius;
			rec.mat_ptr = mat_ptr;
			return true;
		}
	}
	return false;
}

bool moving_sphere::bounding_box(float t0, float t1, aabb &box) const {
	box = aabb::surrounding_box(aabb(center(t0) - vec3(radius, radius, radius), center(t0) + vec3(radius, radius, radius)),
											aabb(center(t1) - vec3(radius, radius, radius), center(t1) + vec3(radius, radius, radius)));
	return true;
}