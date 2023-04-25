/*
** EPITECH PROJECT, 2023
** Raytracer/Ray.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include "Math/Vector3D.hpp"
#include "Math/Point3D.hpp"

namespace Raytracer {

using RayOrigin = Math::Point3D;
using RayOriginValue = Math::Point3DValue;
using RayDirection = Math::Vector3D;
using RayDirectionValue = Math::Vector3DValue;

static const unsigned short Angle3DValueMax = Raytracer::Angle3DValueMax;

class Ray {
public: // Main Attributes
    Raytracer::RayOrigin origin;
    Raytracer::RayDirection direction;
public:
    Ray(void);
    Ray(Raytracer::RayOrigin const origin);
    Ray(Raytracer::RayDirection const direction);
    Ray(Raytracer::RayOrigin const origin, Raytracer::RayDirection const \
        direction);
    Ray(Raytracer::RayDirection const direction, Raytracer::RayOrigin const \
        origin);
    Ray(Ray const &other);
    ~Ray() = default;
    //
    void operator=(Ray const &other);
    Ray operator+(Ray const &other) const;
    Ray operator-(Ray const &other) const;
    Ray operator*(Ray const &other) const;
    Ray operator/(Ray const &other) const;
    void operator+=(Ray const &other);
    void operator-=(Ray const &other);
    void operator*=(Ray const &other);
    void operator/=(Ray const &other);
    bool operator==(Ray const &other) const;
    bool operator!=(Ray const &other) const;
    //
    /// @brief Compute the position of the destination
    Raytracer::RayOrigin destination(void) const;
    /// @brief Compute the distance between the origin and the destination
    Raytracer::RayDirectionValue length(void) const;
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Ray const &vector);
