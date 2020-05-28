//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <random>
//#include <cfloat>
//#include "sphere.h"
//#include "hitable_list.h"
//#include "camera.h"
//#define rgb(tmp) int(255.99 * tmp)
//#define rand_num(generator) std::generate_canonical<double, 10>(generator)
//using std::cout;
//
//vec3 color(const ray &r, hitable *world) {
//	hit_record rec;
//	if (world->hit(r, 0.0, FLT_MAX, rec)) {
//		return 0.5 * vec3(rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1);
//	} else {
//		vec3 unit_direction = unit_vector(r.direction());
//		float t = 0.5 * (unit_direction.y() + 1.0);
//		return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
//	}
//}
//
//int main() {
//	freopen("G:/vec3.ppm", "w", stdout);
//	int nx = 200;
//	int ny = 100;
//	int ns = 100;
//	cout << "P3\n" << nx << " " << ny << "\n255\n";
//	
//	std::random_device rd;
//	std::mt19937_64 gen(rd());
//
//	hitable *list[2];
//	list[0] = new sphere(vec3(0, 0, -1), 0.5);
//	list[1] = new sphere(vec3(0, -100.5, -1), 100);
//	hitable *world = new hitable_list(list, 2);
//	camera cam;
//	for (int j = ny - 1; j >= 0; --j) {
//		for (int i = 0; i < nx; ++i) {
//			vec3 col(0, 0, 0);
//			for (int s = 0; s < ns; ++s) {
//				float u = float(i + rand_num()) / float(nx);
//				float v = float(j + rand_num()) / float(ny);
//				ray r = cam.getRay(u, v);
//				vec3 p = r.point_at_parameter(2.0);
//				col += color(r, world);
//			}
//			col /= float(ns);
//			int ir = rgb(col[0]);
//			int ig = rgb(col[1]);
//			int ib = rgb(col[2]);
//
//			cout << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	return 0;
//}