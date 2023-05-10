/*
** EPITECH PROJECT, 2023
** Raytracer/Texture.cpp
** File description:
** -
*/

#include "Raytracer/Texture.hpp"

Raytracer::Texture::Texture(void)
{ }

Raytracer::Texture::Texture(Raytracer::TextureMirrorValue const mirrorValue) :
    mirrorValue(mirrorValue)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color) :
    color(color), light(RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color, \
    Raytracer::TextureMirrorValue const mirrorValue) : color(color), \
    light(RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES), mirrorValue(mirrorValue)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color, Raytracer::Color \
    const &light) : color(color), light(light)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color, Raytracer::Color \
    const &light, Raytracer::TextureMirrorValue const mirrorValue) : \
    color(color), light(light), mirrorValue(mirrorValue)
{ }

Raytracer::Texture::Texture(Raytracer::Color const &color, Raytracer::Color \
    const &light, Raytracer::TextureMirrorValue const mirrorValue, bool const \
    isPureLight) : color(color), light(light), mirrorValue(mirrorValue), \
    isPureLight(isPureLight)
{ }

Raytracer::Texture::Texture(Raytracer::Texture const &other) :
    color(other.color), light(other.light), mirrorValue(other.mirrorValue), \
    isPureLight(other.isPureLight)
{ }

void Raytracer::Texture::operator=(Raytracer::Texture const &other)
{
    color = other.color; light = other.light; mirrorValue = other.mirrorValue;
    isPureLight = other.isPureLight;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Texture const \
    &texture)
{
    stream << "T(" << texture.color << '|' << texture.light << '|' << \
        texture.mirrorValue << ')';
    return stream;
}
