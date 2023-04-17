/*
** EPITECH PROJECT, 2023
** Raytracer/Scene.hpp
** File description:
** -
*/

#pragma once
#include <list>
#include "Raytracer/Camera.hpp"
#include "Raytracer/Display.hpp"
#include "Shape/IShape.hpp"

namespace Raytracer {

class Scene {
public: // Main Attributes
    std::list<Shape::Shape> shapes;
    Raytracer::Camera camera;
public:
    Raytracer::Display render(void);
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Scene const &scene);
