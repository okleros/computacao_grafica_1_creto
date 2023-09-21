struct Ray
{
	Vec3 origin{0.0, 0.0, 0.0};
	Vec3 direction{1.0, 1.0, 1.0};

	Ray() {}
	Ray(const Vec3& origin, const Vec3& direction): origin(origin), direction(direction) {}
};