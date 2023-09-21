#include <iostream>
#include "vector.hpp"

int main(int argc, char const **argv)
{
	Vec2 v2(1.0f, 1.0f);
	Vec3 v3(1.0f, 1.0f, 1.0f);
	Vec4 v4(1.0f, 1.0f, 1.0f, 1.0f);
	Vec4 v5(v3, 1.0f);
	Vec4 v6(v2, 1.0f, 1.0f);

	Vec4 v7 = normalize(v6);

	v2.normalize();
	v3.normalize();
	v4.normalize();

	std::cout << v2.x << " " << v2.y << std::endl;
	std::cout << v3.x << " " << v3.y << " " << v3.z << std::endl;
	std::cout << v7.x << " " << v7.y << " " << v7.z << " " << v7.w << std::endl;

	return 0;
}