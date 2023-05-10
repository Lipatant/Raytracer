/*
** EPITECH PROJECT, 2023
** Shape/DirectionalLight.cpp
** File description:
** -
*/

#include "Shape/DirectionalLight.hpp"

#define SHAPE_DIRECTIONALLIGHT_NAME "DirectionalLight"
#define SHAPE_DIRECTIONALLIGHT_FOI(X) ((360 - foi) / 180 - 1)

Shape::DirectionalLight::DirectionalLight(Math::Point3D const center, \
    Math::Vector3D const direction, DirectionalLightFOI const foi) : \
    AShape(SHAPE_DIRECTIONALLIGHT_NAME), _center(center), \
    _direction(direction.normalized()), _foi(SHAPE_DIRECTIONALLIGHT_FOI(foi))
{
    _isPureLight = true;
}

Shape::DirectionalLight::DirectionalLight(Math::Point3D const center, \
    Math::Vector3D const direction, DirectionalLightFOI const foi, \
    Raytracer::Color const &color) : AShape(SHAPE_DIRECTIONALLIGHT_NAME, \
    Raytracer::Texture(Raytracer::Color(0, 0, 0, 0), color)), \
    _center(center), _direction(direction.normalized()), \
    _foi(SHAPE_DIRECTIONALLIGHT_FOI(foi))
{
    _isPureLight = true;
}

Shape::DirectionalLight::DirectionalLight(Math::Point3D const center, \
    Math::Vector3D const direction, DirectionalLightFOI const foi, \
    Raytracer::Texture const &texture) : AShape(SHAPE_DIRECTIONALLIGHT_NAME, \
    texture), _center(center), _direction(direction.normalized()), \
    _foi(SHAPE_DIRECTIONALLIGHT_FOI(foi))
{
    _isPureLight = true;
}

Raytracer::HitPointList Shape::DirectionalLight::hitPoints(Raytracer::Ray \
    const &ray) const
{
    Raytracer::Texture texture(_texture);
    Math::Vector3D inbetween(_center - ray.origin);
    Math::Point3DValue dotProduct(inbetween.normalized().dot(_direction));

//    std::cerr << dotProduct << ' ' << _foi << std::endl;
    if (-dotProduct < _foi)
        return {};
    texture.isPureLight = true;
    return {Raytracer::HitPoint(inbetween.length(), _center, texture, \
        inbetween * -1)};
}

Math::Point3D Shape::DirectionalLight::getCenter(void) const
{
    return _center;
}
