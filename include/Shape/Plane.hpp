/*
** EPITECH PROJECT, 2023
** Shape/Plane.hpp
** File description:
** -
*/

#pragma once
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Shape/AShape.hpp"

namespace Shape {

class Plane : public AShape
{
protected:
    Math::Point3D _origin;
    Math::Vector3D _u;
    Math::Vector3D _v;
public:
    Plane(Math::Point3D const origin, Math::Vector3D const u, Math::Vector3D \
        const v);
    Plane(Math::Point3D const origin, Math::Vector3D const u, Math::Vector3D \
        const v, Raytracer::Texture const &texture);
    Plane(Math::Point3D const a, Math::Point3D const b, Math::Point3D const c);
    Plane(Math::Point3D const a, Math::Point3D const b, Math::Point3D const \
        c, Raytracer::Texture const &texture);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
};

}
