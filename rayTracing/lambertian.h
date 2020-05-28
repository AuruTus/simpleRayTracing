#pragma once
#include <random>
#include "material.h"
#include "rand_num.h"

class lambertian : public material {
public:
	vec3 albedo;
	lambertian(const vec3 &albedo) : albedo(albedo) {}
	virtual bool scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &scattered) const {
		vec3 target = rec.p + rec.normal + rtRand::random_in_unit_sphere();
		scattered = ray(rec.p, target - rec.p, r_in.time());
		attenuation = albedo;
		return true;
	}
};