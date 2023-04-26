/*
** EPITECH PROJECT, 2023
** Raytracer/TextureReflection.cpp
** File description:
** -
*/

#include "Raytracer/TextureReflection.hpp"

Raytracer::TextureReflection::TextureReflection(void)
{ }

Raytracer::TextureReflection::TextureReflection(Raytracer::Color const &color) :
    color(color), light(color)
{ }

Raytracer::TextureReflection::TextureReflection(Raytracer::Color const &color, Raytracer::Color \
    const &light) : color(color), light(light)
{ }

Raytracer::TextureReflection::TextureReflection(Raytracer::TextureReflection const &other) :
    color(other.color), light(other.light)
{ }

void Raytracer::TextureReflection::operator=(Raytracer::TextureReflection \
    const &other)
{
    centering = other.centering; forcedCentering = other.forcedCentering;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::TextureReflection \
    const &reflection)
{
    stream << "T(" << TextureReflection.color << '|' << TextureReflection.light << ')';
    return stream;
}
