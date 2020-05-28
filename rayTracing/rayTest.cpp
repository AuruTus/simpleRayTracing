//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include "ray.h"
//#define rgb(tmp) int(255.99 * tmp)
//using std::cout;
//
//float hitSphere(const vec3 &center, float radius, const ray &r) {
//	vec3 oc = r.origin() - center;
//	float a = r.direction() % r.direction();
//	float b = 2.0 * (oc % r.direction());
//	float c = oc % oc - radius * radius;
//	float discriminant = b * b - 4 * a * c;
//	if (discriminant < 0.0) {
//		return -1.0;
//	} else {
//		return (-b - sqrt(discriminant)) / (2.0 * a);
//	}
//}
//
//vec3 color(const ray &r) {
//	float t = hitSphere(vec3(0, 0, -1), 0.5, r);
//	if (t > 0.0) {
//		vec3 N = unit_vector(r.point_at_parameter(t) - vec3(0, 0, -1));
//		return 0.5 * vec3(N.x() + 1, N.y() + 1, N.z() + 1);
//	}
//	vec3 unit_direction = unit_vector(r.direction());
//	t = 0.5 * (unit_direction.y() + 1.0);
//	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
//}
////vec3 color(const ray &r) {
////	if (hitSphere(vec3(0, 0, -1), 0.5, r))
////		return vec3(1, 0, 0);
////	vec3 unit_direction = unit_vector(r.direction());
////	float t = 0.5 * (unit_direction.y() + 1.0);
////	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
////}
//
////vec3 color(const ray &r) {
////	vec3 unit_direction = unit_vector(r.direction());
////	float t = 0.5 * (unit_direction.y() + 1.0);
////	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
////}
//
//
//int main() {
//	freopen("G:/vec3.ppm", "w", stdout);
//	int nx = 200;
//	int ny = 100;
//	cout << "P3\n" << nx << " " << ny << "\n255\n";
//	vec3 lower_left_corner(-2.0, -1.0, -1.0);
//	vec3 horizontal(4.0, 0.0, 0.0);
//	vec3 vertical(0.0, 2.0, 0.0);
//	vec3 origin(0.0, 0.0, 0.0);
//	for (int j = ny - 1; j >= 0; --j) {
//		for (int i = 0; i < nx; ++i) {
//			float u = float(i) / float(nx);	
//			float v = float(j) / float(ny);
//			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
//			vec3 col = color(r);
//			int ir = rgb(col[0]);
//			int ig = rgb(col[1]);
//			int ib = rgb(col[2]);
//
//			cout << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	return 0;
//}