/*
** EPITECH PROJECT, 2023
** Math/Angle3D/Operators.cpp
** File description:
** -
*/

#include "Math/Angle3D.hpp"

void Math::Angle3D::operator=(Math::Angle3D const &other)
{
    x = other.x; y = other.y; z = other.z;
}

Math::Angle3D Math::Angle3D::operator+(Math::Angle3D const &other) const
{
    return Math::Angle3D(x + other.x, y + other.y, z + other.z);
}

Math::Angle3D Math::Angle3D::operator-(Math::Angle3D const &other) const
{
    return Math::Angle3D(x - other.x, y - other.y, z - other.z);
}

Math::Angle3D Math::Angle3D::operator*(Math::Angle3D const &other) const
{
    return Math::Angle3D(x * other.x, y * other.y, z * other.z);
}

Math::Angle3D Math::Angle3D::operator/(Math::Angle3D const &other) const
{
    return Math::Angle3D(x / other.x, y / other.y, z / other.z);
}

void Math::Angle3D::operator+=(Math::Angle3D const &other)
{
    x += other.x; y += other.y; z += other.z;
}

void Math::Angle3D::operator-=(Math::Angle3D const &other)
{
    x -= other.x; y -= other.y; z -= other.z;
}

void Math::Angle3D::operator*=(Math::Angle3D const &other)
{
    x *= other.x; y *= other.y; z *= other.z;
}

void Math::Angle3D::operator/=(Math::Angle3D const &other)
{
    x /= other.x; y /= other.y; z /= other.z;
}

bool Math::Angle3D::operator==(Math::Angle3D const &other) const
{
    return (x == other.x && y == other.y && z == other.z);
}

bool Math::Angle3D::operator!=(Math::Angle3D const &other) const
{
    return (x != other.x || y != other.y || z != other.z);
}
