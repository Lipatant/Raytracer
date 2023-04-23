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
    Raytracer::HitPointList rayListCollisions(Raytracer::Ray const &ray);
    Raytracer::Display render(void);
    Raytracer::DisplayPixel renderAt(std::size_t const x, std::size_t const y);
    Raytracer::Color renderFromList(Raytracer::HitPointList hitPointList, \
        Raytracer::Color light, std::size_t const recurrence);
    //
//    void operator<<(Shape::Shape &shape);
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Scene const &scene);
