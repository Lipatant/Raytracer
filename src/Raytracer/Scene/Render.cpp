/*
** EPITECH PROJECT, 2023
** Raytracer/Scene/Render.cpp
** File description:
** -
*/

#include <ctime>
#include <vector>
#include "Raytracer/Scene.hpp"

Raytracer::Display Raytracer::Scene::render(void)
{
    Raytracer::Display display(camera.width, camera.height);
    std::size_t displayWidth = display.width();
    std::size_t displayHeight = display.height();

    std::srand(std::time(nullptr));
    camera.rotation.normalize();
    if (shapes.size() < 1)
        return display;
    for (std::size_t x = 0; x < displayWidth; x++) {
        std::cout << x + 1 << " / " << displayWidth << " (" << \
            static_cast<double>(x + 1) / displayWidth * 100 << "%)" << \
            std::endl;
        for (std::size_t y = 0; y < displayHeight; y++)
            display.at(x, y) = renderAt(x, y);
    }
    return display;
}
