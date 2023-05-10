/*
** EPITECH PROJECT, 2023
** Shape/AmbientLight.cpp
** File description:
** -
*/

#include "Shape/AmbientLight.hpp"

#define SHAPE_AMBIENTLIGHT_NAME "AmbientLight"

Shape::AmbientLight::AmbientLight(Math::Point3D const center) : \
    AShape(SHAPE_AMBIENTLIGHT_NAME), _center(center)
{
    _isPureLight = true;
}

Shape::AmbientLight::AmbientLight(Math::Point3D const center, \
    Raytracer::Color const &color) : AShape(SHAPE_AMBIENTLIGHT_NAME, \
    Raytracer::Texture(Raytracer::Color(0, 0, 0, 0), color)), _center(center)
{
    _isPureLight = true;
}

Shape::AmbientLight::AmbientLight(Math::Point3D const center, \
    Raytracer::Texture const &texture) : AShape(SHAPE_AMBIENTLIGHT_NAME, \
    texture), _center(center)
{
    _isPureLight = true;
}

Raytracer::HitPointList Shape::AmbientLight::hitPoints(Raytracer::Ray const \
    &ray) const
{
    Raytracer::Texture texture(_texture);
    Math::Vector3D inbetween(_center - ray.origin);

    texture.isPureLight = true;
    return {Raytracer::HitPoint(inbetween.length(), _center, texture, \
        inbetween * -1)};
}

Math::Point3D Shape::AmbientLight::getCenter(void) const
{
    return _center;
}
