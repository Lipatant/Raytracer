/*
** EPITECH PROJECT, 2023
** Raytracer/Texture.cpp
** File description:
** -
*/

#include "Raytracer/Texture.hpp"

Raytracer::Texture::Texture(void)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color) :
    color(color), light(RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color, Raytracer::Color \
    const &light) : color(color), light(light)
{ }

Raytracer::Texture::Texture(Raytracer::Texture const &other) :
    color(other.color), light(other.light)
{ }

void Raytracer::Texture::operator=(Raytracer::Texture const &other)
{
    color = other.color; light = other.light;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Texture const \
    &texture)
{
    stream << "T(" << texture.color << '|' << texture.light << ')';
    return stream;
}
