#pragma once
#include "material.h"
#include "rand_num.h"

vec3 reflect(const vec3 &v, const vec3 &n) {
	return v - 2 * (v % n) * n;
}

class metal : public material {
public:
	vec3 albedo;
	float fuzz = 0;
	metal(const vec3 &albedo) : albedo(albedo) {}

	metal(const vec3 &albedo, float fuzz) : albedo(albedo) {
		if (fuzz < 1) { this->fuzz = fuzz; }
		else { this->fuzz = 1; }
	}
	virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const {
		vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
		scattered = ray(rec.p, reflected + fuzz * rtRand::random_in_unit_sphere(), r_in.time());
		attenuation = albedo;
		return (scattered.direction() % rec.normal) > 0;
	}
};
