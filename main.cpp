#include <iostream>

#include "renderer.hpp"

int main(int argc, char **argv) {
    Renderer renderer;
    Scene scene;

    int frameCounter = 0;

    scene.spheres.push_back(Sphere(Vec3(-0.8f,  0.0f, -2.0f), Vec4(1.0f, 0.0f, 0.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3( 0.0f,  0.0f, -2.0f), Vec4(0.0f, 1.0f, 0.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3( 0.8f,  0.0f, -2.0f), Vec4(0.0f, 0.0f, 1.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3(-0.8f, -0.8f, -2.0f), Vec4(1.0f, 1.0f, 0.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3( 0.0f, -0.8f, -2.0f), Vec4(0.0f, 1.0f, 1.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3( 0.8f, -0.8f, -2.0f), Vec4(1.0f, 0.0f, 1.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3(-0.8f,  0.8f, -2.0f), Vec4(1.0f, 0.0f, 1.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3( 0.0f,  0.8f, -2.0f), Vec4(0.0f, 1.0f, 1.0f, 1.0f), 0.4));
    scene.spheres.push_back(Sphere(Vec3( 0.8f,  0.8f, -2.0f), Vec4(1.0f, 1.0f, 0.0f, 1.0f), 0.4));

    bool quit = false;
    while (!quit) {
        renderer.render(scene);
        std::cout << ++frameCounter << std::endl;

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
