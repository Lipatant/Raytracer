/*
** EPITECH PROJECT, 2023
** Raytracer/Ray.cpp
** File description:
** -
*/

#include "Raytracer/Ray.hpp"

Raytracer::RayOrigin Raytracer::Ray::destination(void) const
{
    return (origin + direction);
}

Raytracer::RayDirectionValue Raytracer::Ray::length(void) const
{
    return direction.length();
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Ray const &vector)
{
    stream << "R(" << vector.origin << '|' << vector.direction << ')';
    return stream;
}
