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
    Math::Vector3D normal = Math::Vector3D(_u.cross(_v)).normalized();
    double divisor = ray.direction.dot(normal);
    double discriminent = 0;

    if (divisor == 0) {
        if ((_origin + _u - ray.origin).dot(normal) == 0)
            return {Raytracer::HitPoint(0.0, ray.origin, _texture, normal)};
        return {};
    }
    discriminent = (_origin + _u - ray.origin).dot(normal) / divisor;
    return {Raytracer::HitPoint(discriminent, ray.origin + \
        ray.direction.normalized() * discriminent, _texture, normal)};
}