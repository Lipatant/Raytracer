/*
** EPITECH PROJECT, 2023
** Shape/IShape.hpp
** File description:
** -
*/

#pragma once
#include <list>
#include <memory>
#include <iostream>
#include "Math/Point3D.hpp"
#include "Raytracer/Texture.hpp"
#include "Raytracer/HitPoint.hpp"
#include "Raytracer/Ray.hpp"

namespace Shape {

class IShape
{
public:
    virtual ~IShape() = default;
    //
    virtual bool hits(Raytracer::Ray const &ray) const = 0;
    virtual Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) \
        const = 0;
    //
    virtual Math::Point3D getCenter(void) const = 0;
    //
    virtual Raytracer::Texture texture(void) = 0;
    virtual Raytracer::Texture texture(void) const = 0;
    virtual std::string name(void) const = 0;
    virtual bool isPureLight(void) const = 0;
};

using Shape = std::unique_ptr<IShape>;

template <typename T, typename... _Args>
static Shape createShape(_Args&&... __args)
{
    return std::make_unique<T>(std::forward<_Args>(__args)...);
}

}

std::ostream &operator<<(std::ostream &stream, Shape::Shape const &shape);
