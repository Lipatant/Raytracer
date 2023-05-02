/*
** EPITECH PROJECT, 2023
** Math/Vector3D/Constructors.cpp
** File description:
** -
*/

#include "Math/Vector3D.hpp"

Math::Vector3D::Vector3D(void) :
    Point3D(1, 1, 1)
{ }

Math::Vector3D::Vector3D(Math::Vector3DValue const x, Math::Vector3DValue \
    const y, Math::Vector3DValue const z) : Point3D(static_cast \
    <Math::Point3DValue>(x), static_cast<Math::Point3DValue>(y), \
    static_cast<Math::Point3DValue>(z))
{ }

Math::Vector3D::Vector3D(Math::Point3D const &point) :
    Point3D(point)
{ }

Math::Vector3D::Vector3D(Vector3D const &other) :
    Point3D(static_cast<Math::Point3DValue>(other.x), static_cast \
    <Math::Point3DValue>(other.y), static_cast<Math::Point3DValue>(other.z)), \
    _normalizedX(other._normalizedX), _normalizedY(other._normalizedY), \
    _normalizedZ(other._normalizedZ)
{ }
