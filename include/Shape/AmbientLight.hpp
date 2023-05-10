/*
** EPITECH PROJECT, 2023
** Shape/AmbientLight.hpp
** File description:
** -
*/

#pragma once
#include "Shape/AShape.hpp"

namespace Shape {

class AmbientLight : public AShape {
protected:
    Math::Point3D _center;
public:
    AmbientLight(Math::Point3D const center);
    AmbientLight(Math::Point3D const center, Raytracer::Color const &color);
    AmbientLight(Math::Point3D const center, Raytracer::Texture const \
        &texture);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
    //
    Math::Point3D getCenter(void) const override;
};

}
