#pragma once
#include "hitable_list.h"
#include "rand_num.h"

class bvh_node: public hitable_list {
public:
	aabb box;
	hitable *left = NULL;
	hitable *right = NULL;

	static int box_x_compare(const void *a, const void *b);
	static int box_y_compare(const void *a, const void *b);
	static int box_z_compare(const void *a, const void *b);

	bvh_node() {}
	bvh_node(hitable **l, int n, float time0, float time1);
	virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const;
	virtual bool bounding_box(float t0, float t1, aabb &box) const;
};