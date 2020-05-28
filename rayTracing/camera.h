#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "ray.h"
#include "rand_num.h"

class camera {
public:
	vec3 origin;
	vec3 lower_left_corner;
	vec3 horizontal;
	vec3 vertical;
	vec3 u, v, w;
	float time0, time1;
	float lens_radius;

	//camera() :
	//	origin(vec3(0.0, 0.0, 0.0)),
	//	lower_left_corner(vec3(-2.0, -1.0, -1.0)),
	//	horizontal(vec3(4.0, 0.0, 0.0)),
	//	vertical(vec3(0.0, 2.0, 0.0)) {}
	camera();

	//camera(float vfov, float aspect) {
	//	float theta = vfov * M_PI / 180;
	//	float half_height = tan(theta / 2);
	//	float half_width = aspect * half_height;
	//	lower_left_corner = vec3(-half_width, -half_height, -1.0);
	//	horizontal = vec3(2 * half_width, 0.0, 0.0);
	//	vertical = vec3(0.0, 2 * half_height, 0.0);
	//	origin = vec3(0.0, 0.0, 0.0);
	//}
	camera(float vfov, float aspect);

	//camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect) {
	//	//vec3 u, v, w;
	//	float theta = vfov * M_PI / 180;
	//	float half_height = tan(theta / 2);
	//	float half_width = aspect * half_height;
	//	origin = lookfrom;
	//	w = unit_vector(lookfrom - lookat);
	//	u = unit_vector(vup ^ w);
	//	v = w ^ u;
	//	lower_left_corner = origin - half_width * u - half_height * v - w;
	//	horizontal = 2 * half_width * u;
	//	vertical = 2 * half_height * v;
	//}	
	camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect);
	
	//camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist) {
	//	//vec3 u, v, w;
	//	lens_radius = aperture / 2;
	//	float theta = vfov * M_PI / 180;
	//	float half_height = tan(theta / 2);
	//	float half_width = aspect * half_height;
	//	origin = lookfrom;
	//	w = unit_vector(lookfrom - lookat);
	//	u = unit_vector(vup ^ w);
	//	v = w ^ u;
	//	lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
	//	horizontal = 2 * half_width * focus_dist * u;
	//	vertical = 2 * half_height * focus_dist * v;
	//}		
	camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist);

	//camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist, float t0, float t1) {
	//	//vec3 u, v, w;
	//	time0 = t0;
	//	time1 = t1;
	//	lens_radius = aperture / 2;
	//	float theta = vfov * M_PI / 180;
	//	float half_height = tan(theta / 2);
	//	float half_width = aspect * half_height;
	//	origin = lookfrom;
	//	w = unit_vector(lookfrom - lookat);
	//	u = unit_vector(vup ^ w);
	//	v = w ^ u;
	//	lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
	//	horizontal = 2 * half_width * focus_dist * u;
	//	vertical = 2 * half_height * focus_dist * v;
	//}
	camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist, float t0, float t1);

	//ray getRay(float u, float v) { 
	//	return ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);
	//}

	//ray getRay(float s, float t) { 
	//	vec3 rd = lens_radius * rtRand::random_in_unit_disk();
	//	vec3 offset = u * rd.x() + v * rd.y();
	//	float time = time0 + rand_num() * (time1 - time0);
	//	return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset, time);
	//}
	ray getRay(float s, float t);
};