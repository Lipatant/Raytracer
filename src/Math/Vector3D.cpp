/*
** EPITECH PROJECT, 2023
** Math/Vector3D.cpp
** File description:
** -
*/

#include "Flags.hpp"
#include "Math/Vector3D.hpp"
#include <cmath>

#define VECTOR3D_DEFAULT_CENTERING 0.0
#define VECTOR3D_DEFAULT_FORCED_CENTERING 0.0
#define VECTOR3D_DEFAULT_INVERTED false

void Math::Vector3D::normalize(void)
{
    double len = length();

    x /= len;
    y /= len;
    z /= len;
}

Math::Vector3D Math::Vector3D::normalized(void) const
{
    Math::Vector3D vector(*this);

    vector.normalize();
    return vector;
}

Math::Vector3D Math::Vector3D::variation(void) const
{
    return variation(VECTOR3D_DEFAULT_CENTERING, \
        VECTOR3D_DEFAULT_FORCED_CENTERING, VECTOR3D_DEFAULT_INVERTED);
}

Math::Vector3D Math::Vector3D::variation(double const centering) const
{
    return variation(centering, VECTOR3D_DEFAULT_FORCED_CENTERING, \
        VECTOR3D_DEFAULT_INVERTED);
}

Math::Vector3D Math::Vector3D::variation(double const centering, double const \
    forcedCentering) const
{
    return variation(centering, forcedCentering, VECTOR3D_DEFAULT_INVERTED);
}

Math::Vector3D Math::Vector3D::variation(bool const inverted) const
{
    return variation(VECTOR3D_DEFAULT_CENTERING, \
        VECTOR3D_DEFAULT_FORCED_CENTERING, inverted);
}

Math::Vector3D Math::Vector3D::variation(double const centering, bool const \
    inverted) const
{
    return variation(centering, VECTOR3D_DEFAULT_FORCED_CENTERING, inverted);
}

Math::Vector3D Math::Vector3D::variation(FLAG_UNUSED double const centering, \
    double const forcedCentering, bool const inverted) const
{
    if (forcedCentering >= 1.0)
        return this->normalized();
    Math::Vector3D randomVector( \
        (static_cast<double>(std::rand()) / RAND_MAX) * 1.0, \
        (static_cast<double>(std::rand()) / RAND_MAX) * 1.0, \
        (static_cast<double>(std::rand()) / RAND_MAX) * 1.0);
    Math::Vector3DValue dotProduct = dot(randomVector);
    Math::Vector3D dotProductSign((dotProduct >= 0 ? 1 : -1), \
        (dotProduct >= 0 ? 1 : -1), (dotProduct >= 0 ? 1 : -1));

    if (inverted) {
        dotProductSign = Math::Vector3D((dotProduct < 0 ? 1 : -1), \
            (dotProduct < 0 ? 1 : -1), (dotProduct < 0 ? 1 : -1));
    }
    if (randomVector == Math::Vector3D(0, 0, 0))
        randomVector = Math::Vector3D();
    if (forcedCentering <= 0.0)
        randomVector = (randomVector * dotProductSign) + this->normalized() * \
            centering;
    else
        randomVector = (randomVector * dotProductSign * (1 - \
            forcedCentering)) + (this->normalized() * (forcedCentering + \
            centering));
    return randomVector.normalized();
}

std::ostream &operator<<(std::ostream &stream, Math::Vector3D const &vector)
{
    stream << "v(" << vector.x << ',' << vector.y << ',' << vector.z << ')';
    return stream;
}
