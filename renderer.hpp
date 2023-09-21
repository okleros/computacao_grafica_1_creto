#pragma once

#include <SDL2/SDL.h>

#include "scene.hpp"
#include "ray.hpp"

const int WIDTH = 600;
const int HEIGHT = 600;

namespace Utils {
	uint32_t toRGBA(const Vec3& v) {
		uint8_t r = (uint8_t) (v.r * 255.0f);
		uint8_t g = (uint8_t) (v.g * 255.0f);
		uint8_t b = (uint8_t) (v.b * 255.0f);
		uint8_t a = (uint8_t) (1.0 * 255.0f);

		return (r << 24) | (g << 16) | (b << 8) | a;
	}

	uint32_t toRGBA(const Vec4& v) {
		uint8_t r = (uint8_t) (v.r * 255.0f);
		uint8_t g = (uint8_t) (v.g * 255.0f);
		uint8_t b = (uint8_t) (v.b * 255.0f);
		uint8_t a = (uint8_t) (v.a * 255.0f);

		return (r << 24) | (g << 16) | (b << 8) | a; 
	}

	uint32_t index(const Vec2& v) { return WIDTH * v.y + v.x; }

	uint32_t index(float x, float y) { return WIDTH * y + x; }
}

struct Renderer
{
	Renderer() { initEverything(); }

	void setPixel(const Vec2&, const Vec3&);
	void setPixel(const Vec2&, const Vec4&);
	void clear();

	int initEverything();
	void destroyEverything();

	Vec4 traceRay(const Scene&, Ray);
	void randomizePixels();
	void render(const Scene&);

private:
	SDL_Renderer* renderer;
	SDL_Window* window;
	uint32_t pixels[WIDTH * HEIGHT];
};

Vec4 Renderer::traceRay(const Scene& scene, Ray ray) {
	if (scene.spheres.size() == 0)
		return Vec4(Vec3(0.1f), 1.0);

	// Raycasting
	ray.direction.normalize();

	const Sphere* closest = nullptr;

	float hitDistance = FLT_MAX;

	for (const Sphere& sphere : scene.spheres) {
		Vec3 origin = ray.origin - sphere.position;

		float a = dot(ray.direction);
		float b = 2.0f * dot(origin, ray.direction);
		float c = dot(origin) - sphere.radius * sphere.radius;

		float discriminant = b * b - 4.0f * a * c;

		if (discriminant < 0)
			continue;

		float t1 = (-b - (sqrt(discriminant))) / (2.0f * a);

		if (t1 < hitDistance) {
			hitDistance = t1;
			closest = &sphere;
		}
	}

	if (closest == nullptr)
		return Vec4(Vec3(0.1f), 1.0f);

	Vec3 origin = ray.origin - closest->position;
	Vec3 h1 = origin + ray.direction * hitDistance;
	Vec3 normal = normalize(h1);

	Vec3 lightDirection(0.0f, 0.0f, -1.0f);
	lightDirection.normalize();

	float intensity = std::max(0.0f, dot(normal, -lightDirection));

	return closest->albedo * intensity;	
}

void Renderer::setPixel(const Vec2& pos, const Vec3& color) { pixels[Utils::index(pos)] = Utils::toRGBA(color); }

void Renderer::setPixel(const Vec2& pos, const Vec4& color) { pixels[Utils::index(pos)] = Utils::toRGBA(color); }

void Renderer::clear() { memset(pixels, 0, sizeof(pixels)); }

void Renderer::randomizePixels() {
    for (int y = 0; y < HEIGHT; ++y)
    {
    	for (int x = 0; x < WIDTH; ++x)
    	{
        	setPixel(Vec2(x, y), Vec3((float) ((float) x / (float) WIDTH), (float) ((float) y / (float) HEIGHT), 0.0));
    	}
    }
}

int Renderer::initEverything() {
	// Clearing the frame buffer
	clear();

	// Seed random library
	std::srand((unsigned) time(NULL));
    
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create a window
    window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create window: %s", SDL_GetError());
        return 1;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create renderer: %s", SDL_GetError());
        return 1;
    }
    
    SDL_SetWindowResizable(window, SDL_FALSE);

    return 0;
}

void Renderer::render(const Scene& scene) {
	clear();

	Ray ray;

	ray.origin = Vec3(0.0f, 0.0f, 2.0f);

	for (int y = 0; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
		{
			Vec2 coord = {x / (float) WIDTH, y / (float) HEIGHT};
			coord = coord * 2.0f - 1.0f;

			ray.direction = Vec3(coord, -1.0f);

			Vec4 color = traceRay(scene, ray);
			color = clamp(color, Vec4(0.0f), Vec4(1.0f));

			pixels[Utils::index(x, y)] = Utils::toRGBA(color);
		}
	}

    SDL_Surface *surface = SDL_CreateRGBSurfaceFrom(pixels, WIDTH, HEIGHT, 32, WIDTH * 4, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create surface: %s", SDL_GetError());
    }

    // Create a texture from the surface
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create texture: %s", SDL_GetError());
    }

    // Render the texture
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Renderer::destroyEverything() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}