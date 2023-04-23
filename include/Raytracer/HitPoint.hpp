/*
** EPITECH PROJECT, 2023
** Raytracer/Camera.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include <list>
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Raytracer/Texture.hpp"

namespace Raytracer {

class HitPoint {
public: // Main Attributes
    double distance = -1;
    Math::Point3D position;
    Raytracer::Texture texture;
    Math::Vector3D reflect; // Normal vector
public:
    HitPoint(void);
    HitPoint(Math::Point3D const &position);
    HitPoint(Raytracer::Texture const &texture);
    HitPoint(Math::Vector3D const &reflect);
    HitPoint(Math::Point3D const &position, Raytracer::Texture const &texture);
    HitPoint(Raytracer::Texture const &texture, Math::Vector3D const &reflect);
    HitPoint(Math::Point3D const &position, Math::Vector3D const &reflect);
    HitPoint(Math::Point3D const &position, Raytracer::Texture const \
        &texture, Math::Vector3D const &reflect);
    //
    HitPoint(double const distance);
    HitPoint(double const distance, Math::Point3D const &position);
    HitPoint(double const distance, Raytracer::Texture const &texture);
    HitPoint(double const distance, Math::Vector3D const &reflect);
    HitPoint(double const distance, Math::Point3D const &position, \
        Raytracer::Texture const &texture);
    HitPoint(double const distance, Raytracer::Texture const &texture, \
        Math::Vector3D const &reflect);
    HitPoint(double const distance, Math::Point3D const &position, \
        Math::Vector3D const &reflect);
    HitPoint(double const distance, Math::Point3D const &position, \
        Raytracer::Texture const &texture, Math::Vector3D const &reflect);
    //
    bool operator==(Raytracer::HitPoint const &other);
    bool operator!=(Raytracer::HitPoint const &other);
    bool operator<(Raytracer::HitPoint const &other);
    bool operator<=(Raytracer::HitPoint const &other);
    bool operator>(Raytracer::HitPoint const &other);
    bool operator>=(Raytracer::HitPoint const &other);
};

using HitPointList = std::list<Raytracer::HitPoint>;

}

std::ostream &operator<<(std::ostream &stream, Raytracer::HitPoint const &hit);

std::ostream &operator<<(std::ostream &stream, Raytracer::HitPointList const \
    &hits);
