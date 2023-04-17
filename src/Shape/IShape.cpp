/*
** EPITECH PROJECT, 2023
** Shape/IShape.cpp
** File description:
** -
*/

#include "Shape/IShape.hpp"

std::ostream &operator<<(std::ostream &stream, Shape::Shape const &shape)
{
    stream << shape->name();
    return stream;
}
