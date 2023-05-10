/*
** EPITECH PROJECT, 2023
** Shape/DirectionalLight.hpp
** File description:
** -
*/

#pragma once
#include "Shape/AShape.hpp"

namespace Shape {

using DirectionalLightFOI = double;

class DirectionalLight : public AShape {
protected:
    Math::Point3D _center;
    Math::Vector3D _direction;
    DirectionalLightFOI _foi; // Field of illumination
public:
    DirectionalLight(Math::Point3D const center, Math::Vector3D const \
        direction, double const foi);
    DirectionalLight(Math::Point3D const center, Math::Vector3D const \
        direction, double const foi, Raytracer::Color const &color);
    DirectionalLight(Math::Point3D const center, Math::Vector3D const \
        direction, double const foi, Raytracer::Texture const &texture);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
    //
    Math::Point3D getCenter(void) const override;
};

}
