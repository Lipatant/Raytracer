/*
** EPITECH PROJECT, 2023
** Math/Point3D.cpp
** File description:
** -
*/

#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include <cmath>

Math::Point3D Math::Point3D::cross(Math::Point3D const &other) const
{
    return (Math::Point3D(
        y * other.z - z * other.y,
        x * other.z - z * other.x,
        x * other.y - y * other.x
    ));
}

Math::Point3D Math::Point3D::cross(Math::Vector3D const &other) const
{
    return (Math::Point3D(
        y * other.z - z * other.y,
        x * other.z - z * other.x,
        x * other.y - y * other.x
    ));
}

Math::Point3DValue Math::Point3D::dot(Math::Point3D const &other) const
{
    return (x * other.x + y * other.y + z * other.z);
}

Math::Point3DValue Math::Point3D::dot(Math::Vector3D const &other) const
{
    return (x * other.x + y * other.y + z * other.z);
}

Math::Point3DValue Math::Point3D::length(void) const
{
    return sqrt(std::abs(x * x + y * y + z * z));
}

Math::Point3DValue Math::Point3D::length(Math::Point3D const &origin) const
{
    Math::Point3D relative(x, y, z);

    relative -= origin;
    return relative.length();
}

std::ostream &operator<<(std::ostream &stream, Math::Point3D const &point)
{
    stream << "p(" << point.x << ',' << point.y << ',' << point.z << ')';
    return stream;
}
