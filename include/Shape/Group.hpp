/*
** EPITECH PROJECT, 2023
** Shape/Group.hpp
** File description:
** -
*/

#pragma once
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Shape/AShape.hpp"
#include <list>

namespace Shape {

class Group : public AShape
{
protected:
    Math::Point3D _center;
    std::list<Shape> _shapes;
public:
    Group(void);
    Group(Math::Point3D const center);
    Group(std::list<Shape> &shapes);
    Group(Math::Point3D const center, std::list<Shape> &shapes);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
    //
    Math::Point3D getCenter(void) const override;
};

}
