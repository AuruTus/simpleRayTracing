#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cfloat>
//#include "rand_num.h"
#include "sphere.h"
#include "hitable_list.h"
#include "camera.h"
#include "metal.h"
#include "lambertian.h"
#include "dielectric.h"
#include "moving_sphere.h"
#include "bvh_node.h"
#define rgb(tmp) int(255.99 * tmp)
using std::cout;

vec3 color(const ray &r, hitable *world, int depth) {
	hit_record rec;
	if (world->hit(r, 0.001, FLT_MAX, rec)) {
		ray scattered;
		vec3 attenuation;
		if (depth < 20 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			return attenuation * color(scattered, world, depth + 1);
		} else {
			return vec3(0, 0, 0);
		}
	} else {
		vec3 unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
	}
}

hitable * random_scene() {
	int n = 50000;
	hitable **list = new hitable*[n + 1];
	//list[0] = new sphere(vec3(0, -1000, 0), 1000, new lambertian(vec3(0.5, 0.5, 0.5)));
	list[0] = new sphere(vec3(0, -1000, 0), 1000, new metal(vec3(0.7, 0.6, 0.5), 0.0));
	int i = 1;
	int up_bound = 5;
	int low_bound = 0;
	for (int a = low_bound; a < up_bound; ++a) {
		for (int b = low_bound; b < up_bound; ++b) {
			float choose_mat = rand_num();
			vec3 center(a + 0.9 * rand_num(), 0.2, b + 0.9 * rand_num());
			if ((center - vec3(4, 0.2, 0)).length() > 0.9) {
				if (choose_mat < 0.8) {
					list[i++] = new moving_sphere(center, center + vec3(0, 0.5 * rand_num(), 0), 0.0, 1.0, 0.2,
						new lambertian(vec3(rand_num() * rand_num(), rand_num() * rand_num(), rand_num() * rand_num())));
				} else if (choose_mat < 0.95) {
					list[i++] = new sphere(center, 0.2, 
						new metal(vec3(0.5 * (1 + rand_num()), 0.5 * (1 + rand_num()), 0.5 * (1 + rand_num())), 0.5 * rand_num()));
				} else {
					list[i++] = new sphere(center, 0.2, new dielectric(rand_num() + 1));
				}
			}
		}
	}
	list[i++] = new sphere(vec3(0, 1, 0), 1.0, new dielectric(1.5));
	list[i++] = new sphere(vec3(-4, 1, 0), 1.0, new lambertian(vec3(0.4, 0.2, 0.1)));
	list[i++] = new sphere(vec3(4, 1, 0), 1.0, new metal(vec3(0.7, 0.6, 0.5), 0.0));
	
	return new hitable_list(list, i);
}

int main() {
	freopen("G:/vec3.ppm", "w", stdout);
	int nx = 800;
	int ny = 640;
	int ns = 100;
	cout << "P3\n" << nx << " " << ny << "\n255\n";
	
	float R = cos(M_PI / 4);
	//hitable *list[4];
	//hitable *list[5];
	//hitable *list[2];
	//list[0] = new sphere(vec3(0, 0, -1), 0.5, new lambertian(vec3(0.1, 0.2, 0.5)));
	////list[0] = new sphere(vec3(-R, 0, -1), R, new lambertian(vec3(0, 0, 1)));
	//list[1] = new sphere(vec3(0, -100.5, -1), 100, new lambertian(vec3(0.8, 0.8, 0.0)));
	//list[1] = new sphere(vec3(-1, 0, -1), 0.5, new lambertian(vec3(1, 0, 1)));
	////list[1] = new sphere(vec3(R, 0, -1), R, new lambertian(vec3(1, 0, 0)));
	////list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2), rand_num()));
	//list[2] = new sphere(vec3(1, 0, -1), 0.5, new metal(vec3(0.8, 0.6, 0.2)));
	////list[3] = new sphere(vec3(-1, 0, -1), 0.5, new metal(vec3(0.8, 0.8, 0.8)));
	//list[3] = new sphere(vec3(-1, 0, -1), 0.5, new dielectric(1.5));
	//list[4] = new sphere(vec3(-1, 0, -1), -0.45, new dielectric(1.5));
	////hitable *world = new hitable_list(list, 4);
	//hitable *world = new hitable_list(list, 5);
	//hitable *world = new hitable_list(list, 2);
	hitable *world = random_scene();
	//vec3 lookfrom(3, 3, 2);
	//vec3 lookat(0, 0, -1);
	//float dist_to_focus = (lookfrom - lookat).length();
	//float aperture = 2.0;
	vec3 lookfrom(13, 2, 3);
	vec3 lookat(0, 0, 0);
	float dist_to_focus = (lookfrom - lookat).length();
	float aperture = 0.0;
	//camera cam;
	//camera cam(90, float(nx) / float(ny));
	//camera cam(vec3(-2, 2, 1), vec3(0, 0, -1), vec3(0, 1, 0), 90, float(nx) / float(ny));
	camera cam(lookfrom, lookat, vec3(0, 1, 0), 20, float(nx) / float(ny), aperture, dist_to_focus, 0.0, 1.0);
	for (int j = ny - 1; j >= 0; --j) {
		for (int i = 0; i < nx; ++i) {
			vec3 col(0, 0, 0);
			for (int s = 0; s < ns; ++s) {
				float u = float(i + rand_num()) / float(nx);
				float v = float(j + rand_num()) / float(ny);
				ray r = cam.getRay(u, v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world, 0);
			}
			col /= float(ns);
			col = vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
			int ir = rgb(col[0]);
			int ig = rgb(col[1]);
			int ib = rgb(col[2]);

			cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return 0;
}