/*
** EPITECH PROJECT, 2023
** Raytracer/Camera.cpp
** File description:
** -
*/

#include "Raytracer/Camera.hpp"

Raytracer::Camera::Camera(void)
{ }

Raytracer::Camera::Camera(Raytracer::CameraPosition const position) :
    position(position)
{ }

Raytracer::Camera::Camera(Raytracer::CameraDirection const direction) :
    direction(direction)
{ }

Raytracer::Camera::Camera(Raytracer::CameraPosition const position, \
    Raytracer::CameraDirection const direction) :
    position(position), direction(direction)
{ }

std::ostream &operator<<(std::ostream &stream, Raytracer::Camera const &camera)
{
    stream << "Camera(" << camera.position << '|' << camera.direction << '|' \
        << camera.width << 'x' << camera.height << '|' << camera.fov << ')' \
        << std::endl;
    return stream;
}
