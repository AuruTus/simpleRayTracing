#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
//#include <cmath>
#include <cstdio>
#include <iostream>

class vec3 {
#define esqr(i) e[i] * e[i]
public:
	float e[3];

	vec3() {}
	vec3(const vec3 &v) : e{v.e[0], v.e[1], v.e[2]} {}
	vec3(float e0, float e1, float e2) : e{ e0, e1, e2 } {}

	inline float x() { return e[0]; }
	inline float y() { return e[1]; }
	inline float z() { return e[2]; }
	inline float r() { return e[0]; }
	inline float g() { return e[1]; }
	inline float b() { return e[2]; }

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	inline float operator[] (int i) const { return e[i]; }
	
	vec3& operator+=(const vec3 &v2);
	vec3& operator-=(const vec3 &v2);
	vec3& operator*=(const vec3 &v2);
	vec3& operator/=(const vec3 &v2);
	vec3& operator*=(const float t);
	vec3& operator/=(const float t);

	inline float length() const {
		return sqrt(esqr(0) + esqr(1) + esqr(2));
	}
	inline float squaredLength() const {
		return esqr(0) + esqr(1) + esqr(2);
	}
	inline void make_unit_vector();
};

std::istream& operator>>(std::istream &is, vec3 &t);

std::ostream& operator<<(std::ostream &os, const vec3 &t);

vec3 operator+(const vec3 &v1, const vec3 &v2);

vec3 operator-(const vec3 &v1, const vec3 &v2);

vec3 operator*(const vec3 &v1, const vec3 &v2);

vec3 operator/(const vec3 &v1, const vec3 &v2);

vec3 operator*(float t, const vec3 &v);

vec3 operator/(vec3 v, float t);

vec3 operator*(const vec3 &v, float t);

//dot product
float operator%(const vec3 &v1, const vec3 &v2);
//cross product
vec3 operator^(const vec3 &v1, const vec3 &v2);

vec3 unit_vector(vec3 v);