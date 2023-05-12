/*
** EPITECH PROJECT, 2023
** Shape/Group.cpp
** File description:
** -
*/

#include "Shape/Group.hpp"
#include <cmath>

Shape::Group::Group(void) : \
    AShape("Group")
{ }

Shape::Group::Group(Math::Point3D const center) : \
    AShape("Group"), _center(center)
{ }

Shape::Group::Group(std::list<Shape> &shapes) : \
    AShape("Group")
{
    for (auto &shape: shapes)
        _shapes.push_back(std::move(shape));
}

Shape::Group::Group(Math::Point3D const center, std::list<Shape> &shapes) : \
    AShape("Group"), _center(center)
{
    for (auto &shape: shapes)
        _shapes.push_back(std::move(shape));
}

Math::Point3D Shape::Group::getCenter(void) const
{
    return _center;
}

Raytracer::HitPointList Shape::Group::hitPoints(Raytracer::Ray const &ray) \
    const
{
    Raytracer::HitPointList hitPointList;
    Raytracer::Ray newRay(ray);

    newRay.origin -= _center;
    for (auto const &shape: _shapes) {
        for (auto &hitPoint: shape->computeHitPoints(newRay, _scale)) {
            hitPoint.position += _center;
            hitPointList.push_back(hitPoint);
        }
    }
    return hitPointList;
}
