/*
** EPITECH PROJECT, 2023
** Shape/Sphere.hpp
** File description:
** -
*/

#pragma once
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Shape/AShape.hpp"

namespace Shape {

class Sphere : public AShape
{
protected:
    Math::Point3D _center;
    Math::Vector3DValue _radius;
public:
    Sphere(Math::Point3D const center, Math::Vector3DValue const radius);
    Sphere(Math::Point3D const center, Math::Vector3DValue const radius, \
        Raytracer::Texture const &texture);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
};

}
