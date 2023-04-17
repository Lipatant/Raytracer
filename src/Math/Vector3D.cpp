/*
** EPITECH PROJECT, 2023
** Math/Vector3D.cpp
** File description:
** -
*/

#include "Math/Vector3D.hpp"
#include <cmath>

std::ostream &operator<<(std::ostream &stream, Math::Vector3D const &vector)
{
    stream << "v(" << vector.x << ',' << vector.y << ',' << vector.z << ')';
    return stream;
}
