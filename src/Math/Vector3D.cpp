/*
** EPITECH PROJECT, 2023
** Math/Vector3D.cpp
** File description:
** -
*/

#include "Math/Vector3D.hpp"
#include <cmath>

Math::Vector3D Math::Vector3D::variation(void) const
{
    return variation(0.0, false);
}

Math::Vector3D Math::Vector3D::variation(double const centering) const
{
    return variation(centering, false);
}

Math::Vector3D Math::Vector3D::variation(bool const inverted) const
{
    return variation(0.0, inverted);
}

Math::Vector3D Math::Vector3D::variation(double const centering, bool const \
    inverted) const
{
    if (centering >= 1.0)
        return *this;
    Math::Vector3D angle( \
        (static_cast<double>(std::rand()) / RAND_MAX) * 1.0, \
        (static_cast<double>(std::rand()) / RAND_MAX) * 1.0, \
        (static_cast<double>(std::rand()) / RAND_MAX) * 1.0);
    Math::Vector3DValue dotProduct = dot(angle);
    Math::Vector3D dotProductSign((dotProduct >= 0 ? 1 : -1), \
        (dotProduct >= 0 ? 1 : -1), (dotProduct >= 0 ? 1 : -1));

    if (inverted) {
        dotProductSign = Math::Vector3D((dotProduct < 0 ? 1 : -1), \
            (dotProduct < 0 ? 1 : -1), (dotProduct < 0 ? 1 : -1));
    }
    if (angle == Math::Vector3D(0, 0, 0))
        angle = Math::Vector3D();
    if (centering <= 0.0)
        return (angle * dotProductSign);
    return (angle * dotProductSign) * centering;
}

std::ostream &operator<<(std::ostream &stream, Math::Vector3D const &vector)
{
    stream << "v(" << vector.x << ',' << vector.y << ',' << vector.z << ')';
    return stream;
}
