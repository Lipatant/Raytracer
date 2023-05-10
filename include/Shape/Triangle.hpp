/*
** EPITECH PROJECT, 2023
** Shape/Triangle.hpp
** File description:
** -
*/

#pragma once
#include "Shape/AShape.hpp"

namespace Shape {

class Triangle : public AShape
{
protected:
    Math::Point3D _a;
    Math::Point3D _b;
    Math::Point3D _c;
    bool _front = true;
    bool _back = true;
public:
    Triangle(Math::Point3D const a, Math::Point3D const b, Math::Point3D \
        const c);
    Triangle(Math::Point3D const a, Math::Point3D const b, Math::Point3D \
        const c, bool const front, bool const back);
    Triangle(Math::Point3D const a, Math::Point3D const b, Math::Point3D \
        const c, Raytracer::Texture const &texture);
    Triangle(Math::Point3D const a, Math::Point3D const b, Math::Point3D \
        const c, bool const front, bool const back, Raytracer::Texture \
        const &texture);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
};

}
