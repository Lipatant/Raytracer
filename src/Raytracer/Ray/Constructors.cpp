/*
** EPITECH PROJECT, 2023
** Raytracer/Ray/Constructors.cpp
** File description:
** -
*/

#include "Raytracer/Ray.hpp"

Raytracer::Ray::Ray(void) :
    origin(0,0,0), direction(1, 1, 1)
{ }

Raytracer::Ray::Ray(Raytracer::RayDirection const direction) :
    origin(0,0,0), direction(direction)
{ }

Raytracer::Ray::Ray(Raytracer::RayOrigin const origin, \
    Raytracer::RayDirection const direction) :
    origin(origin), direction(direction)
{ }

Raytracer::Ray::Ray(Ray const &other) :
    origin(other.origin), direction(other.direction)
{ }
