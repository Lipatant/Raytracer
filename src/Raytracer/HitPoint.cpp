/*
** EPITECH PROJECT, 2023
** Raytracer/Camera.cpp
** File description:
** -
*/

#include "Raytracer/HitPoint.hpp"

Raytracer::HitPoint::HitPoint(void)
{ }

Raytracer::HitPoint::HitPoint(Math::Point3D const &position) :
    position(position)
{ }

Raytracer::HitPoint::HitPoint(Raytracer::Texture const &texture) :
    texture(texture)
{ }

Raytracer::HitPoint::HitPoint(Math::Vector3D const &reflect) :
    reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(Math::Point3D const &position, \
    Raytracer::Texture const &texture) : position(position), texture(texture)
{ }

Raytracer::HitPoint::HitPoint(Raytracer::Texture const &texture, \
    Math::Vector3D const &reflect) : texture(texture), reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(Math::Point3D const &position, Math::Vector3D \
    const &reflect) : position(position), reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(Math::Point3D const &position, \
    Raytracer::Texture const &texture, Math::Vector3D const &reflect) :
    position(position), texture(texture), reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(double const distance) :
    distance(distance)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Math::Point3D const \
    &position) : distance(distance), position(position)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Raytracer::Texture const \
    &texture) : distance(distance), texture(texture)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Math::Vector3D const \
    &reflect) : distance(distance), reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Math::Point3D const \
    &position, Raytracer::Texture const &texture) :
    distance(distance), position(position), texture(texture)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Raytracer::Texture const \
    &texture, Math::Vector3D const& reflect) :
    distance(distance), texture(texture), reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Math::Point3D const \
    &position, Math::Vector3D const& reflect) :
    distance(distance), position(position), reflect(reflect)
{ }

Raytracer::HitPoint::HitPoint(double const distance, Math::Point3D const \
    &position, Raytracer::Texture const &texture, Math::Vector3D const& \
    reflect) : distance(distance), position(position), texture(texture), \
    reflect(reflect)
{ }

bool Raytracer::HitPoint::operator==(Raytracer::HitPoint const &other)
{
    return (distance == other.distance);
}

bool Raytracer::HitPoint::operator!=(Raytracer::HitPoint const &other)
{
    return (distance != other.distance);
}

bool Raytracer::HitPoint::operator<(Raytracer::HitPoint const &other)
{
    return (distance < other.distance);
}

bool Raytracer::HitPoint::operator<=(Raytracer::HitPoint const &other)
{
    return (distance <= other.distance);
}

bool Raytracer::HitPoint::operator>(Raytracer::HitPoint const &other)
{
    return (distance > other.distance);
}

bool Raytracer::HitPoint::operator>=(Raytracer::HitPoint const &other)
{
    return (distance >= other.distance);
}

std::ostream &operator<<(std::ostream &stream, Raytracer::HitPoint const &hit)
{
    stream << "H(" << hit.distance << '|' << hit.position << '|' << \
        hit.reflect << ')';
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::HitPointList const \
    &hits)
{
    for (auto const &hit: hits)
        stream << hit;
    return stream;
}
