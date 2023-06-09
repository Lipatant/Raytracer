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
private:
    Math::Point3DValue _normalizedX = 1;
    Math::Point3DValue _normalizedY = 0;
    Math::Point3DValue _normalizedZ = 0;
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
    //
    using Math::Point3D::operator+;
    using Math::Point3D::operator-;
    using Math::Point3D::operator*;
    using Math::Point3D::operator/;
    //
    /// @brief
    void normalize(void);
    /// @brief
    Math::Vector3D normalized(void) const;
    //
    Vector3D variation(void) const;
    Vector3D variation(double const centering) const;
    Vector3D variation(double const centering, double const forcedCentering) \
        const;
    Vector3D variation(bool const inverted) const;
    Vector3D variation(double const centering, bool const inverted) const;
    Vector3D variation(double const centering, double const forcedCentering, \
        bool const inverted) const;
};

}

std::ostream &operator<<(std::ostream &stream, Math::Vector3D const &vector);
