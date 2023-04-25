/*
** EPITECH PROJECT, 2023
** Math/Point3D.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include "Math/Angle3D.hpp"

namespace Math {

using Point3DValue = double;

class Vector3D;

class Point3D {
public: // Main Attributes
    Math::Point3DValue x;
    Math::Point3DValue y;
    Math::Point3DValue z;
public:
    Point3D(void);
    Point3D(Math::Point3DValue const x, Math::Point3DValue const y, \
        Math::Point3DValue const z);
    Point3D(Point3D const &other);
    ~Point3D() = default;
    //
    void operator=(Point3D const &other);
    Point3D operator+(Point3D const &other) const;
    Point3D operator-(Point3D const &other) const;
    Point3D operator*(Point3D const &other) const;
    Point3D operator/(Point3D const &other) const;
    void operator+=(Point3D const &other);
    void operator-=(Point3D const &other);
    void operator*=(Point3D const &other);
    void operator/=(Point3D const &other);
    bool operator==(Point3D const &other) const;
    bool operator!=(Point3D const &other) const;
    //
    Point3D operator+(Math::Point3DValue const value) const;
    Point3D operator-(Math::Point3DValue const value) const;
    Point3D operator*(Math::Point3DValue const value) const;
    Point3D operator/(Math::Point3DValue const value) const;
    //
    /// @brief Compute the dot product (produit scalaire) of this point and
    ///     another
    Math::Point3DValue dot(Point3D const &other) const;
    /// @brief Compute the dot product (produit scalaire) of this point and
    ///     another
    Math::Point3DValue dot(Vector3D const &other) const;
    /// @brief Compute the distance between origin and this point
    /// @param origin (optional) Its value is set to p(0,0,0) by default
    Math::Point3DValue length(void) const;
    /// @brief Compute the distance between origin and this point
    /// @param origin (optional) Its value is set to p(0,0,0) by default
    Math::Point3DValue length(Math::Point3D const &origin) const;
};

}

std::ostream &operator<<(std::ostream &stream, Math::Point3D const &vector);
