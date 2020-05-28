//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include "vec3.h"
//#define color(tmp) int(255.99 * tmp)
//using std::cout;
//
//int main() {
//	freopen("G:/vec3.ppm", "w", stdout);
//	int nx = 200;
//	int ny = 100;
//	cout << "P3\n" << nx << " " << ny << "\n255\n";
//	for (int j = ny - 1; j >= 0; --j) {
//		for (int i = 0; i < nx; ++i) {
//			vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
//			int ir = color(col[0]);
//			int ig = color(col[1]);
//			int ib = color(col[2]);
//
//			cout << ir << " " << ig << " " << ib << "\n";
//		}
//	}
//	return 0;
//}