/*
** EPITECH PROJECT, 2023
** Shape/Sphere.cpp
** File description:
** -
*/

#include "Shape/Sphere.hpp"

Shape::Sphere::Sphere(Math::Point3D const center, Math::Vector3DValue const \
    radius) : AShape("Sphere"), _center(center), _radius(radius)
{ }

bool Shape::Sphere::hits(Raytracer::Ray const &ray) const
{
    return false;
}
