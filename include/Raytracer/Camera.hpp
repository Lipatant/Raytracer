/*
** EPITECH PROJECT, 2023
** Raytracer/Camera.hpp
** File description:
** -
*/

#pragma once
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Raytracer/Ray.hpp"

namespace Raytracer {

using CameraPosition = Math::Point3D;
using CameraDirection = Math::Vector3D;

class Camera {
public: // Main Attributes
    Raytracer::CameraPosition position;
    Raytracer::CameraDirection direction;
    double fov = 90;
    std::size_t width = 1920;
    std::size_t height = 1080;
public:
    Camera(void);
    Camera(Raytracer::CameraPosition const position);
    Camera(Raytracer::CameraDirection const direction);
    Camera(Raytracer::CameraPosition const position, \
        Raytracer::CameraDirection const direction);
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Camera const \
    &camera);
