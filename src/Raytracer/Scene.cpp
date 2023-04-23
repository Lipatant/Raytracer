/*
** EPITECH PROJECT, 2023
** Raytracer/Scene.cpp
** File description:
** -
*/

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
            if (hitpoint.distance >= 0.05)
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
        return light;
    hitPointList.sort();
    texture = hitPointList.front().texture;
    if (texture.light.a >= Raytracer::ColorValueMaximum)
        return texture.light;
    if (texture.light.a > Raytracer::ColorValueMinimum) {
        return texture.light;
    }
    Raytracer::Ray reflect(hitPointList.front().position, \
        hitPointList.front().reflect);
//    hitPointList.pop_front();
    color = texture.color;
//    return color;
    return color * renderFromList(rayListCollisions(reflect), light, \
        recurrence - 1);
//    return color * renderFromList(hitPointList, light);
}

Raytracer::DisplayPixel Raytracer::Scene::renderAt(std::size_t const x, \
    std::size_t const y)
{
    Raytracer::Texture texture;
    Raytracer::CameraDirection cameraDirection(getDirection(camera, x, y));
    Raytracer::Ray ray(cameraDirection, camera.position);

    texture.light = Raytracer::Color(0.1, 0.1, 0.1);
    texture.color = renderFromList(rayListCollisions(ray), texture.light, 10);
    return texture.color.toDisplayPixel();
}

Raytracer::Display Raytracer::Scene::render(void)
{
    Raytracer::Display display(camera.width, camera.height);
    std::size_t displayWidth = display.width();
    std::size_t displayHeight = display.height();

    camera.rotation.normalize();
    if (shapes.size() < 1)
        return display;
    for (std::size_t x = 0; x < displayWidth; x++)
        for (std::size_t y = 0; y < displayHeight; y++)
            display.at(x, y) = renderAt(x, y);
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
