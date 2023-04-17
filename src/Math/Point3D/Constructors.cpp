/*
** EPITECH PROJECT, 2023
** Math/Point3D/Constructors.cpp
** File description:
** -
*/

#include "Math/Point3D.hpp"

Math::Point3D::Point3D(void) :
    x(0), y(0), z(0)
{ }

Math::Point3D::Point3D(Math::Point3DValue const x, Math::Point3DValue const \
    y, Math::Point3DValue const z) : x(x), y(y), z(z)
{ }

Math::Point3D::Point3D(Point3D const &other) :
    x(other.x), y(other.y), z(other.z)
{ }
