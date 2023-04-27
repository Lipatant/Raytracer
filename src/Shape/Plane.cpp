/*
** EPITECH PROJECT, 2023
** Shape/Plane.cpp
** File description:
** -
*/

#include "Shape/Plane.hpp"
#include <cmath>

#define SHAPE_PLANE_NAME "Plane"

Shape::Plane::Plane(Math::Point3D const origin, Math::Vector3D const u, \
    Math::Vector3D const v) : AShape(SHAPE_PLANE_NAME), _origin(origin), \
    _u(u), _v(v)
{ }

Shape::Plane::Plane(Math::Point3D const origin, Math::Vector3D const u, \
    Math::Vector3D const v, Raytracer::Texture const &texture) : \
    AShape(SHAPE_PLANE_NAME, texture), _origin(origin), _u(u.normalized()), \
    _v(v.normalized())
{ }

Shape::Plane::Plane(Math::Point3D const a, Math::Point3D const b, \
    Math::Point3D const c) : AShape(SHAPE_PLANE_NAME), _origin(a), \
    _u(Math::Vector3D(b - a)), _v(Math::Vector3D(c - a))
{ }

Shape::Plane::Plane(Math::Point3D const a, Math::Point3D const b, \
    Math::Point3D const c, Raytracer::Texture const &texture) : \
    AShape(SHAPE_PLANE_NAME, texture), _origin(a), \
    _u(Math::Vector3D(b - a).normalized()), \
    _v(Math::Vector3D(c - a).normalized())
{ }

Raytracer::HitPointList Shape::Plane::hitPoints(Raytracer::Ray const &ray) \
    const
{
    Math::Vector3D normal = (_u * _v).normalized();
    double d = ray.direction.dot(normal) * -1; // determinent

    return {};
}
