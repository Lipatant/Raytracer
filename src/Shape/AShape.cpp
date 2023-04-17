/*
** EPITECH PROJECT, 2023
** Shape/AShape.cpp
** File description:
** -
*/

#include "Shape/AShape.hpp"

Shape::AShape::AShape(void) :
    _name("UnknownShape")
{ }

Shape::AShape::AShape(std::string const &name) :
    _name(name)
{ }

std::string Shape::AShape::name(void) const
{
    return _name;
}
