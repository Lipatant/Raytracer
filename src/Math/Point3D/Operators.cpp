/*
** EPITECH PROJECT, 2023
** Math/Point3D/Operators.cpp
** File description:
** -
*/

#include "Math/Point3D.hpp"

void Math::Point3D::operator=(Point3D const &other)
{
    x = other.x; y = other.y; z = other.z;
}

Math::Point3D Math::Point3D::operator+(Point3D const &other) const
{
    return Math::Point3D(x + other.x, y + other.y, z + other.z);
}

Math::Point3D Math::Point3D::operator-(Point3D const &other) const
{
    return Math::Point3D(x - other.x, y - other.y, z - other.z);
}

Math::Point3D Math::Point3D::operator*(Point3D const &other) const
{
    return Math::Point3D(x * other.x, y * other.y, z * other.z);
}

Math::Point3D Math::Point3D::operator/(Point3D const &other) const
{
    return Math::Point3D(x / other.x, y / other.y, z / other.z);
}

void Math::Point3D::operator+=(Point3D const &other)
{
    x += other.x; y += other.y; z += other.z;
}

void Math::Point3D::operator-=(Point3D const &other)
{
    x -= other.x; y -= other.y; z -= other.z;
}

void Math::Point3D::operator*=(Point3D const &other)
{
    x *= other.x; y *= other.y; z *= other.z;
}

void Math::Point3D::operator/=(Point3D const &other)
{
    x /= other.x; y /= other.y; z /= other.z;
}

bool Math::Point3D::operator==(Point3D const &other) const
{
    return (x == other.x && y == other.y && z == other.z);
}

bool Math::Point3D::operator!=(Point3D const &other) const
{
    return (x != other.x || y != other.y || z != other.z);
}

//

Math::Point3D Math::Point3D::operator+(Math::Point3DValue const value) const
{
    return Math::Point3D(x + value, y + value, z + value);
}

Math::Point3D Math::Point3D::operator-(Math::Point3DValue const value) const
{
    return Math::Point3D(x - value, y - value, z - value);
}

Math::Point3D Math::Point3D::operator*(Math::Point3DValue const value) const
{
    return Math::Point3D(x * value, y * value, z * value);
}

Math::Point3D Math::Point3D::operator/(Math::Point3DValue const value) const
{
    return Math::Point3D(x / value, y / value, z / value);
}
