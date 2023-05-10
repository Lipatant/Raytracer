/*
** EPITECH PROJECT, 2023
** Shape/Triangle.cpp
** File description:
** -
*/

#include "Shape/Triangle.hpp"
#include <cmath>

#define SHAPE_TRIANGLE_NAME "Triangle"

Shape::Triangle::Triangle(Math::Point3D const a, Math::Point3D const b, \
    Math::Point3D const c) : AShape(SHAPE_TRIANGLE_NAME), _a(a), _b(b), _c(c)
{ }

Shape::Triangle::Triangle(Math::Point3D const a, Math::Point3D const b, \
    Math::Point3D const c, bool const front, bool const back) : \
    AShape(SHAPE_TRIANGLE_NAME), _a(a), _b(b), _c(c), _front(front), \
    _back(back)
{ }

Shape::Triangle::Triangle(Math::Point3D const a, Math::Point3D const b, \
    Math::Point3D const c, Raytracer::Texture const &texture) : \
    AShape(SHAPE_TRIANGLE_NAME, texture), _a(a), _b(b), _c(c)
{ }

Shape::Triangle::Triangle(Math::Point3D const a, Math::Point3D const b, \
    Math::Point3D const c, bool const front, bool const back, \
    Raytracer::Texture const &texture) : \
    AShape(SHAPE_TRIANGLE_NAME, texture), _a(a), _b(b), _c(c), _front(front), \
    _back(back)
{ }

#define vAB vectors[0]
#define vAC vectors[1]

// Möller–Trumbore intersection algorithm
Raytracer::HitPointList Shape::Triangle::hitPoints(Raytracer::Ray const &ray) \
    const
{
    if (!_front && !_back)
        return {};
    double const margin = 0.000001;
    Math::Vector3D const vectors[2] = {_b - _a, _c - _a};
    Math::Vector3D const normal = vAB.cross(vAC);
    Math::Vector3D const vOA = ray.origin - _a;
    Math::Vector3D const normalOAD = vOA.cross(ray.direction);
    double const d = 0 - ray.direction.dot(normal); //determinant
    double const f = 1 / d; //inverted determinent
    double u, v, distance;

    if ((!_front || d < margin) && (!_back || d > (0 - margin)))
        return {};
    u = vAC.dot(normalOAD) * f;
    v = (0 - vAB.dot(normalOAD)) * f;
    if (u < 0.0 || v < 0.0 || (u + v) > 1.0)
        return {};
    distance = vOA.dot(normal) * f;
    return {Raytracer::HitPoint(distance, ray.origin + ray.direction * \
        distance, _texture, normal.normalized())};
}
