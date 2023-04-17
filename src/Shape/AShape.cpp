/*
** EPITECH PROJECT, 2023
** Shape/AShape.cpp
** File description:
** -
*/

#include "Shape/AShape.hpp"

#define FLAG_UNUSED __attribute__((unused))

Shape::AShape::AShape(void) :
    _name("UnknownShape")
{ }

Shape::AShape::AShape(std::string const &name) :
    _name(name)
{ }

bool Shape::AShape::hits(FLAG_UNUSED Raytracer::Ray const &ray) const
{
    return false;
}

std::string Shape::AShape::name(void) const
{
    return _name;
}
