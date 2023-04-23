/*
** EPITECH PROJECT, 2023
** Raytracer/Camera.cpp
** File description:
** -
*/

#include "Raytracer/Camera.hpp"
#include <cmath>

Raytracer::Camera::Camera(void)
{ }

Raytracer::Camera::Camera(Raytracer::CameraPosition const position) :
    position(position)
{ }

Raytracer::Camera::Camera(Raytracer::CameraRotation const rotation) :
    rotation(rotation)
{ }

Raytracer::Camera::Camera(Raytracer::CameraPosition const position, \
    Raytracer::CameraRotation const rotation) :
    position(position), rotation(rotation)
{ }

Raytracer::CameraDirection Raytracer::Camera::direction(void)
{
    if (_storedDirectionComputed && _storedDirectionRotation == rotation)
        return _storedDirection;
    _storedDirection = rotation.direction();
    _storedDirectionRotation = rotation;
    return _storedDirection;
}

Raytracer::CameraDirection Raytracer::Camera::direction(void) const
{
    if (_storedDirectionComputed && _storedDirectionRotation == rotation)
        return _storedDirection;
    return rotation.direction();
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Camera const &camera)
{
    stream << "Camera(" << camera.position << '|' << camera.rotation << '|' \
        << camera.width << 'x' << camera.height << '|' << camera.fov << ')' \
        << std::endl;
    return stream;
}
