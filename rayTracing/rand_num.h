#pragma once
#include <random>
#include "vec3.h"

namespace rtRand {
	#define rand_num() std::generate_canonical<double, 10>(rtRand::gen)

	static std::random_device rd;
	static std::mt19937_64 gen(rd());

	//vec3 random_in_unit_sphere() {
	//	vec3 p;
	//	do {
	//		p = 2.0 * vec3(rand_num(), rand_num(), rand_num()) - vec3(1, 1, 1);
	//	} while (p.squaredLength() >= 1.0);
	//	return p;
	//}
	vec3 random_in_unit_sphere();

	//vec3 random_in_unit_disk() {
	//	vec3 p;
	//	do {
	//		p = 2.0 * vec3(rand_num(), rand_num(), 0) - vec3(1, 1, 0);
	//	} while (p % p >= 1.0);
	//	return p;
	//}
	vec3 random_in_unit_disk();
}