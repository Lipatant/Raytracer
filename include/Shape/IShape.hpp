/*
** EPITECH PROJECT, 2023
** Shape/IShape.hpp
** File description:
** -
*/

#pragma once
#include <memory>
#include <iostream>
#include "Raytracer/Ray.hpp"

namespace Shape {

class IShape
{
public:
    virtual ~IShape() = default;
    //
    virtual bool hits(Raytracer::Ray const &ray) const = 0;
    virtual std::string name(void) const = 0;
};

using Shape = std::unique_ptr<IShape>;

template <typename T>
static Shape createShape(void)
{
    return std::make_unique<T>();
}

}

std::ostream &operator<<(std::ostream &stream, Shape::Shape const &shape);
