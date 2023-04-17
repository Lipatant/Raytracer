/*
** EPITECH PROJECT, 2023
** Shape/IShape.hpp
** File description:
** -
*/

#pragma once
#include <memory>
#include <iostream>

namespace Shape {

class IShape
{
public:
    virtual ~IShape() = default;
    //
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
