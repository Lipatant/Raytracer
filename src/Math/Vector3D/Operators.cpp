/*
** EPITECH PROJECT, 2023
** Math/Vector3D/Operators.cpp
** File description:
** -
*/

#include "Math/Vector3D.hpp"

void Math::Vector3D::operator=(Vector3D const &other)
{
    x = other.x; y = other.y; z = other.z;
    _normalizedX = other._normalizedX;
    _normalizedY = other._normalizedY;
    _normalizedZ = other._normalizedZ;
}

Math::Vector3D Math::Vector3D::operator+(Vector3D const &other) const
{
    return Math::Vector3D(x + other.x, y + other.y, z + other.z);
}

Math::Vector3D Math::Vector3D::operator-(Vector3D const &other) const
{
    return Math::Vector3D(x - other.x, y - other.y, z - other.z);
}

Math::Vector3D Math::Vector3D::operator*(Vector3D const &other) const
{
    return Math::Vector3D(x * other.x, y * other.y, z * other.z);
}

Math::Vector3D Math::Vector3D::operator/(Vector3D const &other) const
{
    return Math::Vector3D(x / other.x, y / other.y, z / other.z);
}

void Math::Vector3D::operator+=(Vector3D const &other)
{
    x += other.x; y += other.y; z += other.z;
}

void Math::Vector3D::operator-=(Vector3D const &other)
{
    x -= other.x; y -= other.y; z -= other.z;
}

void Math::Vector3D::operator*=(Vector3D const &other)
{
    x *= other.x; y *= other.y; z *= other.z;
}

void Math::Vector3D::operator/=(Vector3D const &other)
{
    x /= other.x; y /= other.y; z /= other.z;
}

bool Math::Vector3D::operator==(Vector3D const &other) const
{
    return (x == other.x && y == other.y && z == other.z);
}

bool Math::Vector3D::operator!=(Vector3D const &other) const
{
    return (x != other.x || y != other.y || z != other.z);
}
