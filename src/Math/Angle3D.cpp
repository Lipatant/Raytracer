/*
** EPITECH PROJECT, 2023
** Math/Angle3D.cpp
** File description:
** -
*/

#include <cmath>
#include "Math/Angle3D.hpp"
#include "Math/Vector3D.hpp"

// Degrees to radians conversion
#define D2R(D) ((D / 180.0) * ((double) M_PI))

Math::Vector3D Math::Angle3D::direction(void) const
{
    double xr = D2R(x);
    double yr = D2R(y);

    return Math::Vector3D(cos(xr) * cos(yr), sin(xr) * cos(yr), sin(yr));
}

Math::Angle3D &Math::Angle3D::normalize(void)
{
    fmod(x, Math::Angle3DValueMax);
    fmod(y, Math::Angle3DValueMax);
    fmod(z, Math::Angle3DValueMax);
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Math::Angle3D const &angle)
{
    stream << "a(" << angle.x << ',' << angle.y << ',' << angle.z << ')';
    return stream;
}
