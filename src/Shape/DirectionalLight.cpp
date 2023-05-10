/*
** EPITECH PROJECT, 2023
** Shape/DirectionalLight.cpp
** File description:
** -
*/

#include "Shape/DirectionalLight.hpp"
#include <cmath>

#define SHAPE_DIRECTIONALLIGHT_NAME "DirectionalLight"

Shape::DirectionalLight::DirectionalLight(Math::Point3D const center, \
    Math::Vector3D const direction, Math::Vector3DValue const radius) : \
    Sphere(center, radius, Raytracer::Texture(Raytracer::Color(0, \
    0, 0, 0), Raytracer::Color(1, 1, 1, 1))), _direction(direction)
{ }

Shape::DirectionalLight::DirectionalLight(Math::Point3D const center, \
    Math::Vector3D const direction, Math::Vector3DValue const radius, \
    Raytracer::Color const &color) : Sphere(center, radius, \
    Raytracer::Texture(Raytracer::Color(0, 0, 0, 0), color)), \
    _direction(direction)
{ }

Shape::DirectionalLight::DirectionalLight(Math::Point3D const center, \
    Math::Vector3D const direction, Math::Vector3DValue const radius, \
    Raytracer::Texture const &texture) : Sphere(center, radius, texture), \
    _direction(direction)
{ }

Raytracer::HitPointList Shape::DirectionalLight::hitPoints(Raytracer::Ray \
    const &ray) const
{
    Math::Point3D const positionRelative = ray.origin - _center;
    Math::Point3D hit1;
    Math::Point3D hit2;
    double const a = ray.direction.dot(ray.direction);
    double const b = 2 * positionRelative.dot(ray.direction);
    double const c = positionRelative.dot(positionRelative) - _radius * \
        _radius;
    double const d = b * b - 4 * a * c; // discriment
    double fx1;
    double fx2;
    Math::Vector3DValue dotProduct = \
        _direction.normalized().dot((ray.direction.normalized()));

    if (d < 0 || acos(dotProduct) * 57.2958 > 90)
        return {};
    fx1 = (0 - b - sqrt(d)) / (2 * a);
    fx2 = (0 - b + sqrt(d)) / (2 * a);
    if (fx1 == fx2) {
        hit1 = ray.origin + ray.direction * Math::Vector3D(fx1, fx1, fx1);
        return {Raytracer::HitPoint(fx1, hit1, _texture, \
            Math::Vector3D(hit1 - _center))};
    }
    hit1 = ray.origin + ray.direction * Math::Vector3D(fx1, fx1, fx1);
    hit2 = ray.origin + ray.direction * Math::Vector3D(fx2, fx2, fx2);
    return {
        Raytracer::HitPoint(fx1, hit1, _texture, \
            Math::Vector3D(hit1 - _center)),
        Raytracer::HitPoint(fx2, hit2, _texture, \
            Math::Vector3D(hit2 - _center)),
    };
}
