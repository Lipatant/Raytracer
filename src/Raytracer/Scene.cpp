/*
** EPITECH PROJECT, 2023
** Raytracer/Scene.cpp
** File description:
** -
*/

#include <ctime>
#include <vector>
#include "Raytracer/Scene.hpp"

static Raytracer::CameraDirection getDirection(Raytracer::Camera const \
    camera, std::size_t const x, std::size_t const y)
{
    Raytracer::Camera tiltedCamera = camera;
    double ratio = (0.0 + camera.height) / camera.width;
    double verticalFov = camera.fov * ratio;

    tiltedCamera.rotation.x += ((x - camera.width * 0.5) * camera.fov) /
        camera.width;
    tiltedCamera.rotation.y -= ((y - camera.height * 0.5) * verticalFov) /
        camera.height;
    return tiltedCamera.direction();
}

Raytracer::HitPointList Raytracer::Scene::rayListCollisions(Raytracer::Ray \
    const &ray)
{
    Raytracer::HitPointList hitPointList;

    for (auto const &shape: shapes)
        for (auto const &hitpoint: shape->hitPoints(ray))
            if (hitpoint.distance >= 0.001)
                hitPointList.push_back(hitpoint);
    hitPointList.sort();
    return hitPointList;
}

Raytracer::Color Raytracer::Scene::renderFromList(Raytracer::HitPointList \
    hitPointList, Raytracer::Color light, std::size_t const recurrence)
{
    Raytracer::Texture texture;
    Raytracer::Color color;

    if (recurrence <= 0 || hitPointList.size() < 1)
        return light.withoutAlpha();
    hitPointList.sort();
    texture = hitPointList.front().texture;
    color = texture.color;
    if (texture.light.a >= Raytracer::ColorValueMaximum)
        return texture.light.withoutAlpha();
    if (texture.light.a > Raytracer::ColorValueMinimum) {
        light += texture.light;
        color = texture.light + color * (1 - texture.light.a);
    }
    if (color.a <= Raytracer::ColorValueMinimum)
        return color;
    Raytracer::Ray reflect(hitPointList.front().position, \
        hitPointList.front().reflect);
    reflect.direction = reflect.direction.variation(0.5);
    color *= renderFromList(rayListCollisions(reflect), light, recurrence - 1);
    if (color.a < Raytracer::ColorValueMaximum) {
        hitPointList.pop_front();
        color += renderFromList(hitPointList, light, recurrence) * \
            (1 - color.a);
    }
    return color;
}

Raytracer::DisplayPixel Raytracer::Scene::renderAt(std::size_t const x, \
    std::size_t const y)
{
    Raytracer::Color cumulatedColor;
    Raytracer::Color color;
    Raytracer::Color light;
    Raytracer::CameraDirection cameraDirection(getDirection(camera, x, y));
    Raytracer::Ray ray(cameraDirection, camera.position);
    std::size_t blending = 2;

    if (blending <= 0)
        return color.toDisplayPixel();
    light = Raytracer::Color(0.6, 0.95, 1.0, 0.05);
    for (size_t i = 0; i < blending; i++) {
        color = renderFromList(rayListCollisions(ray), light, 20);
        cumulatedColor.r += color.r;
        cumulatedColor.g += color.g;
        cumulatedColor.b += color.b;
        cumulatedColor.a += color.a;
    }
    cumulatedColor.r /= blending;
    cumulatedColor.g /= blending;
    cumulatedColor.b /= blending;
    cumulatedColor.a /= blending;
    return cumulatedColor.toDisplayPixel();
}

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
        std::cout << x + 1 << " / " << displayWidth << std::endl;
        for (std::size_t y = 0; y < displayHeight; y++) {
            display.at(x, y) = renderAt(x, y);
        }
    }
    return display;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Scene const &scene)
{
    stream << "Camera:" << std::endl << scene.camera << std::endl;
    stream << "Shapes:" << std::endl;
    for (auto const &shape : scene.shapes)
        stream << shape << std::endl;;
    return stream;
}
