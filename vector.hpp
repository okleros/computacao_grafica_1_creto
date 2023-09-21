#pragma once

#include <cmath>

struct Vec2
{
	float x, y;

	Vec2(float i): x(i), y(i) { }
	Vec2(float i, float j): x(i), y(j) { }

	void normalize();
	Vec2 operator - ();
};

struct Vec3
{
	float x, y, z, r, g, b;

	Vec3(float i): x(i), y(i), z(i), r(x), g(y), b(z) { }
	Vec3(float i, float j, float k): x(i), y(j), z(k), r(x), g(y), b(z) { }
	Vec3(const Vec2& v, float k): x(v.x), y(v.y), z(k), r(x), g(y), b(z) { }

	void normalize();
	Vec3 operator - ();
};

struct Vec4
{
	float x, y, z, w, r, g, b, a;
	
	Vec4(float i): x(i), y(i), z(i), w(i), r(x), g(y), b(z), a(w) { }
	Vec4(float i, float j, float k, float l): x(i), y(j), z(k), w(l), r(x), g(y), b(z), a(w) { }
	Vec4(const Vec3& v, float l): x(v.x), y(v.y), z(v.z), w(l), r(x), g(y), b(z), a(w) { }
	Vec4(const Vec2& v, float k, float l): x(v.x), y(v.y), z(k), w(l), r(x), g(y), b(z), a(w) { }

	void normalize();
	Vec4 operator - ();
};

float dot(const Vec2&);
float dot(const Vec3&);
float dot(const Vec4&);

float dot(const Vec2&, const Vec2&);
float dot(const Vec3&, const Vec3&);
float dot(const Vec4&, const Vec4&);

Vec2 operator * (const Vec2&, float);
Vec3 operator * (const Vec3&, float);
Vec4 operator * (const Vec4&, float);

Vec2 operator * (float, const Vec2&);
Vec3 operator * (float, const Vec3&);
Vec4 operator * (float, const Vec4&);

Vec2 operator - (const Vec2&, float);
Vec3 operator - (const Vec3&, float);
Vec4 operator - (const Vec4&, float);

Vec2 operator - (float, const Vec2&);
Vec3 operator - (float, const Vec3&);
Vec4 operator - (float, const Vec4&);

Vec2 operator + (const Vec2&, float);
Vec3 operator + (const Vec3&, float);
Vec4 operator + (const Vec4&, float);

Vec2 operator + (float, const Vec2&);
Vec3 operator + (float, const Vec3&);
Vec4 operator + (float, const Vec4&);

Vec2 operator * (const Vec2&, const Vec2&);
Vec3 operator * (const Vec3&, const Vec3&);
Vec4 operator * (const Vec4&, const Vec4&);

Vec2 operator + (const Vec2&, const Vec2&);
Vec3 operator + (const Vec3&, const Vec3&);
Vec4 operator + (const Vec4&, const Vec4&);

Vec2 operator - (const Vec2&, const Vec2&);
Vec3 operator - (const Vec3&, const Vec3&);
Vec4 operator - (const Vec4&, const Vec4&);

Vec2 normalize(const Vec2&);
Vec3 normalize(const Vec3&);
Vec4 normalize(const Vec4&);

Vec2 clamp(const Vec2&, const Vec2&, const Vec2&);
Vec3 clamp(const Vec3&, const Vec3&, const Vec3&);
Vec4 clamp(const Vec4&, const Vec4&, const Vec4&);

Vec2 normalize(const Vec2& v) { return v * (1 / sqrt(dot(v))); }

Vec3 normalize(const Vec3& v) { return v * (1 / sqrt(dot(v))); }

Vec4 normalize(const Vec4& v) { return v * (1 / sqrt(dot(v))); }

void Vec2::normalize() { *this = *this * (1 / sqrt(dot(*this))); }

void Vec3::normalize() { *this = *this * (1 / sqrt(dot(*this))); }

void Vec4::normalize() { *this = *this * (1 / sqrt(dot(*this))); }

Vec2 operator * (const Vec2& v, float k) { return Vec2(v.x * k, v.y * k); }

Vec3 operator * (const Vec3& v, float k) { return Vec3(v.x * k, v.y * k, v.z * k); }

Vec4 operator * (const Vec4& v, float k) { return Vec4(v.x * k, v.y * k, v.z * k, v.w * k); }

Vec2 operator * (float k, const Vec2& v) { return v * k; }

Vec3 operator * (float k, const Vec3& v) { return v * k; }

Vec4 operator * (float k, const Vec4& v) { return v * k; }

Vec2 operator - (const Vec2& v, float k) { return Vec2(v.x - k, v.y - k); }

Vec3 operator - (const Vec3& v, float k) { return Vec3(v.x - k, v.y - k, v.z - k); }

Vec4 operator - (const Vec4& v, float k) { return Vec4(v.x - k, v.y - k, v.z - k, v.w - k); }

Vec2 operator - (float k, const Vec2& v) { return v - k; }

Vec3 operator - (float k, const Vec3& v) { return v - k; }

Vec4 operator - (float k, const Vec4& v) { return v - k; }

Vec2 operator + (const Vec2& v, float k) { return Vec2(v.x + k, v.y + k); }

Vec3 operator + (const Vec3& v, float k) { return Vec3(v.x + k, v.y + k, v.z + k); }

Vec4 operator + (const Vec4& v, float k) { return Vec4(v.x + k, v.y + k, v.z + k, v.w + k); }

Vec2 operator + (float k, const Vec2& v) { return v + k; }

Vec3 operator + (float k, const Vec3& v) { return v + k; }

Vec4 operator + (float k, const Vec4& v) { return v + k; }

Vec2 operator * (const Vec2& u, const Vec2& v) { return Vec2(u.x * v.x, u.y * v.y); }

Vec3 operator * (const Vec3& u, const Vec3& v) { return Vec3(u.x * v.x, u.y * v.y, u.z * v.z); }

Vec4 operator * (const Vec4& u, const Vec4& v) { return Vec4(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w); }

Vec2 operator + (const Vec2& u, const Vec2& v) { return Vec2(u.x + v.x, u.y + v.y); }

Vec3 operator + (const Vec3& u, const Vec3& v) { return Vec3(u.x + v.x, u.y + v.y, u.z + v.z); }

Vec4 operator + (const Vec4& u, const Vec4& v) { return Vec4(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w); }

Vec2 operator - (const Vec2& u, const Vec2& v) { return Vec2(u.x - v.x, u.y - v.y); }

Vec3 operator - (const Vec3& u, const Vec3& v) { return Vec3(u.x - v.x, u.y - v.y, u.z - v.z); }

Vec4 operator - (const Vec4& u, const Vec4& v) { return Vec4(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w); }

Vec2 Vec2::operator - () { return *this * (-1.0f); }

Vec3 Vec3::operator - () { return *this * (-1.0f); }

Vec4 Vec4::operator - () { return *this * (-1.0f); }

float dot(const Vec2& v) { return dot(v, v); }

float dot(const Vec3& v) { return dot(v, v); }

float dot(const Vec4& v) { return dot(v, v); }

float dot(const Vec2& u, const Vec2& v) { return u.x * v.x + u.y * v.y; }

float dot(const Vec3& u, const Vec3& v) { return u.x * v.x + u.y * v.y + u.z * v.z; }

float dot(const Vec4& u, const Vec4& v) { return u.x * v.x + u.y * v.y + u.z * v.z + u.w * v.w; }

Vec2 clamp(const Vec2& u, const Vec2& v, const Vec2& t) {
	float x = std::min(std::max(u.x, v.x), t.x);
	float y = std::min(std::max(u.y, v.y), t.y);

	return Vec2(x, y);
}

Vec3 clamp(const Vec3& u, const Vec3& v, const Vec3& t) {
	float x = std::min(std::max(u.x, v.x), t.x);
	float y = std::min(std::max(u.y, v.y), t.y);
	float z = std::min(std::max(u.z, v.z), t.z);

	return Vec3(x, y, z);
}

Vec4 clamp(const Vec4& u, const Vec4& v, const Vec4& t) {
	float x = std::min(std::max(u.x, v.x), t.x);
	float y = std::min(std::max(u.y, v.y), t.y);
	float z = std::min(std::max(u.z, v.z), t.z);
	float w = std::min(std::max(u.w, v.w), t.w);

	return Vec4(x, y, z, w);
}