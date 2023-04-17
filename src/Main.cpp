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
    Shape::Sphere sphere1(Math::Point3D(0,0,0),1);
    Raytracer::Display display(50,50);

    std::cout << ray << std::endl;
    std::cout << sphere1.name() << std::endl;
    std::cout << (sphere1.hits(ray) ? "hits!" : "miss") << std::endl;
    if (ac < 2)
        std::cout << display;
    else
        writeFile(av[1], display);
    return 0;
}
