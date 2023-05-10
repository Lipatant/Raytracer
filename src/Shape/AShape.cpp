/*
** EPITECH PROJECT, 2023
** Shape/AShape.cpp
** File description:
** -
*/

#include "Flags.hpp"
#include "Shape/AShape.hpp"

Shape::AShape::AShape(void)
{ }

Shape::AShape::AShape(std::string const &name)
{
    _name = name;
}

Shape::AShape::AShape(Raytracer::Texture const &texture) :
    _texture(texture)
{ }

Shape::AShape::AShape(std::string const &name, Raytracer::Texture const \
    &texture) : _texture(texture)
{
    _name = name;
}

bool Shape::AShape::hits(Raytracer::Ray const &ray) const
{
    return (hitPoints(ray).size() >= 1);
}

Math::Point3D Shape::AShape::getCenter(void) const
{
    return Math::Point3D();
}

Raytracer::HitPointList Shape::AShape::hitPoints(FLAG_UNUSED Raytracer::Ray \
    const &ray) const
{
    return {};
}

Raytracer::Texture Shape::AShape::texture(void)
{
    return _texture;
}

Raytracer::Texture Shape::AShape::texture(void) const
{
    return _texture;
}

std::string Shape::AShape::name(void) const
{
    return _name;
}

bool Shape::AShape::isPureLight(void) const
{
    return _isPureLight;
}
