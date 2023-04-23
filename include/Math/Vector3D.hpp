/*
** EPITECH PROJECT, 2023
** Math/Vector3D.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include "Math/Point3D.hpp"

namespace Math {

using Vector3DValue = double;

class Vector3D : public Math::Point3D
{
public:
    using Point3D::Point3D;
    //
    Vector3D(void);
    Vector3D(Math::Vector3DValue const x, Math::Vector3DValue const y, \
        Math::Vector3DValue const z);
    Vector3D(Point3D const &point);
    Vector3D(Vector3D const &other);
    ~Vector3D() = default;
    //
    void operator=(Vector3D const &other);
    Vector3D operator+(Vector3D const &other) const;
    Vector3D operator-(Vector3D const &other) const;
    Vector3D operator*(Vector3D const &other) const;
    Vector3D operator/(Vector3D const &other) const;
    void operator+=(Vector3D const &other);
    void operator-=(Vector3D const &other);
    void operator*=(Vector3D const &other);
    void operator/=(Vector3D const &other);
    bool operator==(Vector3D const &other) const;
    bool operator!=(Vector3D const &other) const;
};

}

std::ostream &operator<<(std::ostream &stream, Math::Vector3D const &vector);
