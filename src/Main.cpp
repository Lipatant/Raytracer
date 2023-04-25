/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** Main and starting function
*/

#include <exception>
#include <fstream>
#include <iostream>
#include "Math.hpp"
#include "Raytracer.hpp"
#include "Shape.hpp"

static void writeFile(std::string const &filepath, Raytracer::Display const \
    &display)
{
    std::ofstream file;

    file.open(filepath);
    if (!file)
        throw std::runtime_error("Couldn't open a file");
    file << display;
    file.close();
}

int main(int const ac, char const * const * const av)
{
    Raytracer::Ray ray;
    Raytracer::Scene scene;

    scene.camera.width = 1700;
    scene.camera.height = 1000;
    scene.camera.width = 680;
    scene.camera.height = 400;
    scene.camera.position = Math::Point3D(0,0,0);
    scene.camera.rotation = Math::Angle3D(0,0);
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(3,2,1), 1, Raytracer::Texture(Raytracer::Color(1, 0, 0))));
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(3,1,0.1), 0.8, Raytracer::Texture(Raytracer::Color(0, 1, 0))));
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(3,0,0), 1, Raytracer::Texture(Raytracer::Color(0.2, 0.2, 0.7, 0.5))));
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>(
        Math::Point3D(2.7,0,0.6), 0.5, Raytracer::Texture(Raytracer::Color(1, 1, 1, 0.5), Raytracer::Color(1.0, 0.9, 0.2, 1))));
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(2,0,-4.1), 3, Raytracer::Texture(Raytracer::Color(0, 0, 0, 0), Raytracer::Color(1, 1, 1, 0.4))));
    if (ac < 2)
        std::cout << scene.render();
    else
        writeFile(av[1], scene.render());
    return 0;
}
