#pragma once
#include "hitable.h"

class hitable_list : public hitable {
public:
	hitable **list;
	int list_size;
	hitable_list() {}
	hitable_list(hitable **list, int list_size) : list(list), list_size(list_size) {}
	virtual bool hit(const ray &r, float t_min, float t_max, hit_record &rec) const;
	virtual bool bounding_box(float t0, float t1, aabb &box) const;
};