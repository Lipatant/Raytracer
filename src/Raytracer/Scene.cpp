/*
** EPITECH PROJECT, 2023
** Raytracer/Scene.cpp
** File description:
** -
*/

#include "Raytracer/Scene.hpp"

Raytracer::HitPointList Raytracer::Scene::rayListPureLights(Raytracer::Ray \
    const &ray)
{
    Raytracer::HitPointList hitPointList;

    for (auto const &shape: shapes)
        for (auto const &hitpoint: shape->hitPoints(ray))
            if (hitpoint.distance >= 0.0001)
                hitPointList.push_back(hitpoint);
    hitPointList.sort();
    return hitPointList;
}

Raytracer::HitPointList Raytracer::Scene::rayListCollisions(Raytracer::Ray \
    const &ray)
{
    Raytracer::HitPointList hitPointList;

    for (auto const &shape: shapes) {
        if (shape->isPureLight())
            continue;
        for (auto const &hitpoint: shape->hitPoints(ray)) {
            if (hitpoint.distance >= 0.0001 && !hitpoint.texture.isPureLight)
                hitPointList.push_back(hitpoint);
        }
    }
    hitPointList.sort();
    return hitPointList;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Scene const &scene)
{
    stream << "Camera:" << std::endl << scene.camera << std::endl;
    stream << "Shapes:" << std::endl;
    for (auto const &shape : scene.shapes)
        stream << shape << std::endl;;
    return stream;
}
