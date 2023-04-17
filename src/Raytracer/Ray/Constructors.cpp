/*
** EPITECH PROJECT, 2023
** Raytracer/Ray/Constructors.cpp
** File description:
** -
*/

#include "Raytracer/Ray.hpp"

Raytracer::Ray::Ray(void) :
    origin(), direction()
{ }

Raytracer::Ray::Ray(Raytracer::RayDirection const direction) :
    origin(), direction(direction)
{ }

Raytracer::Ray::Ray(Raytracer::RayOrigin const origin) :
    origin(origin), direction()
{ }

Raytracer::Ray::Ray(Raytracer::RayOrigin const origin, \
    Raytracer::RayDirection const direction) :
    origin(origin), direction(direction)
{ }

Raytracer::Ray::Ray(Raytracer::RayDirection const direction, \
    Raytracer::RayOrigin const origin) :
    origin(origin), direction(direction)
{ }

Raytracer::Ray::Ray(Ray const &other) :
    origin(other.origin), direction(other.direction)
{ }
