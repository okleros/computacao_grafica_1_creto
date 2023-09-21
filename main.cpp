#include <iostream>

#include "renderer.hpp"

int main(int argc, char **argv) {
    Renderer renderer;
    Scene scene;

    scene.spheres.push_back(Sphere(Vec3(-0.8f,  0.0f, 0.0f), Vec4(1.0f, 0.0f, 0.0f, 1.0f), 0.5));
    scene.spheres.push_back(Sphere(Vec3( 0.0f,  0.0f, 0.0f), Vec4(0.0f, 1.0f, 0.0f, 1.0f), 0.5));
    scene.spheres.push_back(Sphere(Vec3( 0.8f,  0.0f, 0.0f), Vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.5));

    scene.spheres.push_back(Sphere(Vec3(-0.8f, -0.8f, 0.0f), Vec4(1.0f, 1.0f, 0.0f, 1.0f), 0.5));
    scene.spheres.push_back(Sphere(Vec3( 0.0f, -0.8f, 0.0f), Vec4(0.0f, 1.0f, 1.0f, 1.0f), 0.5));
    scene.spheres.push_back(Sphere(Vec3( 0.8f, -0.8f, 0.0f), Vec4(1.0f, 0.0f, 1.0f, 1.0f), 0.5));

    scene.spheres.push_back(Sphere(Vec3(-0.8f,  0.8f, 0.0f), Vec4(1.0f, 0.0f, 1.0f, 1.0f), 0.5));
    scene.spheres.push_back(Sphere(Vec3( 0.0f,  0.8f, 0.0f), Vec4(0.0f, 1.0f, 1.0f, 1.0f), 0.5));
    scene.spheres.push_back(Sphere(Vec3( 0.8f,  0.8f, 0.0f), Vec4(1.0f, 1.0f, 0.0f, 1.0f), 0.5));

    bool quit = false;
    while (!quit) {
        renderer.render(scene);

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Cleanup
    renderer.destroyEverything();

    return 0;
}