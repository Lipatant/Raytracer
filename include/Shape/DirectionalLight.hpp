/*
** EPITECH PROJECT, 2023
** Shape/DirectionalLight.hpp
** File description:
** -
*/

#pragma once
#include "Shape/Sphere.hpp"

namespace Shape {

class DirectionalLight : public Sphere {
protected:
    Math::Vector3D _direction;
public:
    DirectionalLight(Math::Point3D const center, Math::Vector3D const \
        direction, Math::Vector3DValue const radius);
    DirectionalLight(Math::Point3D const center, Math::Vector3D const \
        direction, Math::Vector3DValue const radius, Raytracer::Color const \
        &color);
    DirectionalLight(Math::Point3D const center, Math::Vector3D const \
        direction, Math::Vector3DValue const radius, Raytracer::Texture \
        const &texture);
    //
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
};

}
