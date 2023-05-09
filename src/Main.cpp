/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** Main and starting function
*/

#include <exception>
#include <fstream>
#include <iostream>
#include "Argument.hpp"
#include "Math.hpp"
#include "Raytracer.hpp"
#include "Shape.hpp"
#include "Obj/Parser.hpp"

#define DEFAULT_MIRROR_CUBE 1.0

Arg::Argument Arg::INPUT;

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

int main(int const ac, char * const * const av)
{
    Raytracer::Ray ray;
    Raytracer::Scene scene;
    Parser::File file;

    file.parseFile(av[1]);
    for (auto const &val: file.shapes)
        std::cout << val.formName << std::endl;
    return 0;
    if (!Arg::INPUT.setArguments(ac, av))
        return 84;
    scene.camera.width = Arg::INPUT.width;
    scene.camera.height = Arg::INPUT.height;
    scene.camera.fov = 180;
    scene.camera.position = Math::Point3D(-1.9,0,0);
    scene.camera.rotation = Math::Angle3D(0,0);
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(0,0,2), 0.5, Raytracer::Texture(Raytracer::Color(1, 1, 1), Raytracer::Color(1, 1, 1, 1))));
    scene.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(0,0,0), 0.8, Raytracer::Texture(Raytracer::Color(1, 1, 1))));
    // Haut
    scene.shapes.push_back(Shape::createShape<Shape::Plane>( \
        Math::Point3D(0,0,2), Math::Vector3D(1,0,0), Math::Vector3D(0,1,0), \
        Raytracer::Texture(Raytracer::Color(1, 1, 1), Raytracer::Color(1, 1, 1, 0.2), DEFAULT_MIRROR_CUBE)));
    // Haut
    scene.shapes.push_back(Shape::createShape<Shape::Plane>( \
        Math::Point3D(0,0,-2), Math::Vector3D(1,0,0), Math::Vector3D(0,1,0), \
        Raytracer::Texture(Raytracer::Color(1, 1, 1), DEFAULT_MIRROR_CUBE)));
    // Arrière
    scene.shapes.push_back(Shape::createShape<Shape::Plane>( \
        Math::Point3D(2,0,0), Math::Vector3D(0,1,0), Math::Vector3D(0,0,1), \
        Raytracer::Texture(Raytracer::Color(0.5, 0.5, 1), DEFAULT_MIRROR_CUBE)));
    // Avant
    scene.shapes.push_back(Shape::createShape<Shape::Plane>( \
        Math::Point3D(-2,0,0), Math::Vector3D(0,1,0), Math::Vector3D(0,0,1), \
        Raytracer::Texture(Raytracer::Color(1, 1, 1), DEFAULT_MIRROR_CUBE)));
    // Gauche
    scene.shapes.push_back(Shape::createShape<Shape::Plane>( \
        Math::Point3D(0,-2,0), Math::Vector3D(1,0,0), Math::Vector3D(0,0,1), \
        Raytracer::Texture(Raytracer::Color(1, 0.5, 0.5), DEFAULT_MIRROR_CUBE)));
    // Droite
    scene.shapes.push_back(Shape::createShape<Shape::Plane>( \
        Math::Point3D(0,2,0), Math::Vector3D(1,0,0), Math::Vector3D(0,0,1), \
        Raytracer::Texture(Raytracer::Color(0.5, 1, 0.5), DEFAULT_MIRROR_CUBE)));
    if (Arg::INPUT.out.empty())
        std::cout << scene.render();
    else
        writeFile(Arg::INPUT.out, scene.render());
    return 0;
}
