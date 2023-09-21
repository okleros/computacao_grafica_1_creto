#pragma once
#include "vector.hpp"

struct Sphere
{
	Vec3 position{1.0f, 1.0f, 1.0f};
	float radius = 10.0f;

	Vec4 albedo{1.0f};

	Sphere(const Vec3& position, const Vec4& albedo, float radius): position(position), albedo(albedo), radius(radius) {}
};