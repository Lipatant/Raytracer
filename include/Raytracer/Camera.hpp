/*
** EPITECH PROJECT, 2023
** Raytracer/Camera.hpp
** File description:
** -
*/

#pragma once
#include "Math/Angle3D.hpp"
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Raytracer/Ray.hpp"

namespace Raytracer {

using CameraDirection = Math::Vector3D;
using CameraPosition = Math::Point3D;
using CameraRotation = Math::Angle3D;

class Camera {
private:
    Raytracer::CameraDirection _storedDirection;
    bool _storedDirectionComputed = false;
    Raytracer::CameraRotation _storedDirectionRotation;
public: // Main Attributes
    Raytracer::CameraPosition position;
    Raytracer::CameraRotation rotation;
    double fov = 90;
    std::size_t width = 1920;
    std::size_t height = 1080;
public:
    Camera(void);
    Camera(Raytracer::CameraPosition const position);
    Camera(Raytracer::CameraRotation const rotation);
    Camera(Raytracer::CameraPosition const position, \
        Raytracer::CameraRotation const rotation);
    //
    Raytracer::CameraDirection direction(void);
    Raytracer::CameraDirection direction(void) const;
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Camera const \
    &camera);
