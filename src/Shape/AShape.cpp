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

Math::Vector3D &Shape::AShape::getScale(void)
{
    return _scale;
}

Math::Vector3D Shape::AShape::getScale(void) const
{
    return _scale;
}

Raytracer::HitPointList Shape::AShape::hitPoints(FLAG_UNUSED Raytracer::Ray \
    const &ray) const
{
    return {};
}

Raytracer::HitPointList Shape::AShape::computeHitPoints(Raytracer::Ray const \
    &ray) const
{
    return hitPoints(ray);
//    return computeHitPoints(ray, Math::Vector3D(1, 1, 1));
}

Raytracer::HitPointList Shape::AShape::computeHitPoints(Raytracer::Ray const \
    &ray, Math::Vector3D additionalScale) const
{
    Math::Vector3D newScale(_scale * additionalScale);
    if (newScale == Math::Vector3D(1, 1, 1)) return hitPoints(ray);
    Raytracer::Ray newRay(ray);
    Math::Point3D center = getCenter();
    Raytracer::HitPointList list;

    newRay.origin /= newScale;
    newRay.direction /= newScale;
    list = hitPoints(newRay);
    newRay.origin *= newScale;
    newRay.direction *= newScale;
    for (auto &point: list) {
        point.position *= newScale;
        point.reflect = (point.reflect * newScale).normalized();
        point.distance = newRay.origin.length(point.position);
    }
    return list;
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
