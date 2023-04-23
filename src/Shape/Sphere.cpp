/*
** EPITECH PROJECT, 2023
** Shape/Sphere.cpp
** File description:
** -
*/

#include "Shape/Sphere.hpp"
#include <cmath>

Shape::Sphere::Sphere(Math::Point3D const center, Math::Vector3DValue const \
    radius) : AShape("Sphere"), _center(center), _radius(radius)
{ }

Shape::Sphere::Sphere(Math::Point3D const center, Math::Vector3DValue const \
    radius, Raytracer::Texture const &texture) :
    AShape("Sphere", texture), _center(center), _radius(radius)
{ }

Raytracer::HitPointList Shape::Sphere::hitPoints(Raytracer::Ray const &ray) \
    const
{
    Math::Point3D positionRelative = ray.origin - _center;
    Math::Point3D hit1;
    Math::Point3D hit2;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * positionRelative.dot(ray.direction);
    double c = positionRelative.dot(positionRelative) - _radius * _radius;
    double d = b * b - 4 * a * c; // discriment
    double fx1;
    double fx2;

    if (d < 0)
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
