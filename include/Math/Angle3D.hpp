/*
** EPITECH PROJECT, 2023
** Math/Angle3D.hpp
** File description:
** -
*/

#pragma once
#include <iostream>

namespace Math {

// From Math/Vector3D
class Vector3D;

using Angle3DValue = double;

static const unsigned short Angle3DValueMax = 360;

class Angle3D {
public: // Main Attributes
    Math::Angle3DValue x;
    Math::Angle3DValue y;
    Math::Angle3DValue z;
public:
    Angle3D(void);
    Angle3D(Math::Angle3DValue const x, Math::Angle3DValue const y);
    Angle3D(Math::Angle3DValue const x, Math::Angle3DValue const y, \
        Math::Angle3DValue const z);
    Angle3D(Math::Angle3D const &other);
    ~Angle3D() = default;
    //
    void operator=(Math::Angle3D const &other);
    Angle3D operator+(Math::Angle3D const &other) const;
    Angle3D operator-(Math::Angle3D const &other) const;
    Angle3D operator*(Math::Angle3D const &other) const;
    Angle3D operator/(Math::Angle3D const &other) const;
    void operator+=(Math::Angle3D const &other);
    void operator-=(Math::Angle3D const &other);
    void operator*=(Math::Angle3D const &other);
    void operator/=(Math::Angle3D const &other);
    bool operator==(Math::Angle3D const &other) const;
    bool operator!=(Math::Angle3D const &other) const;
    //
    Math::Vector3D direction(void) const;
    Angle3D &normalize(void);
};

}

std::ostream &operator<<(std::ostream &stream, Math::Angle3D const &angle);
