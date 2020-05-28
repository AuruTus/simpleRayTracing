#pragma once
#include "vec3.h"

class ray {
public:
	vec3 A;
	vec3 B;
	float _time;

	ray() {}
	//ray(const vec3 &A, const vec3 &B): A(A), B(B) {}
	ray(const vec3 &A, const vec3 &B, float time = 0.0): A(A), B(B), _time(time) {}
	inline vec3 origin() const { return A; }
	inline vec3 direction() const { return B; }
	inline float time()	const { return _time; }
	inline vec3 point_at_parameter(float t) const { return A + t * B; }
};