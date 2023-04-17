/*
** EPITECH PROJECT, 2023
** Math/Point3D.cpp
** File description:
** -
*/

#include "Math/Point3D.hpp"
#include <cmath>

Math::Point3DValue Math::Point3D::dot(Point3D const &other) const
{
    return (x * other.x + y * other.y + z * other.z);
}

Math::Point3DValue Math::Point3D::length(void) const
{
    return sqrt(std::abs(x * x + y * y + z * z));
}

std::ostream &operator<<(std::ostream &stream, Math::Point3D const &vector)
{
    stream << "p(" << vector.x << ',' << vector.y << ',' << vector.z << ')';
    return stream;
}
