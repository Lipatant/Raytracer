/*
** EPITECH PROJECT, 2023
** Math/Angle3D/Constructors.cpp
** File description:
** -
*/

#include "Math/Angle3D.hpp"

Math::Angle3D::Angle3D(void) :
    x(0), y(0), z(0)
{ }

Math::Angle3D::Angle3D(Math::Angle3DValue const x, Math::Angle3DValue const \
    y) : x(x), y(y)
{ }

Math::Angle3D::Angle3D(Math::Angle3DValue const x, Math::Angle3DValue const \
    y, Math::Angle3DValue const z) : x(x), y(y), z(z)
{ }

Math::Angle3D::Angle3D(Math::Angle3D const &other) :
    x(other.x), y(other.y), z(other.z)
{ }
