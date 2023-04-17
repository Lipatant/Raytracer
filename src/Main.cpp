/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** Main and starting function
*/

#include <iostream>
#include "Math.hpp"
#include "Raytracer.hpp"

int main(__attribute__((unused)) int const ac, __attribute__((unused)) \
    char const * const * const av)
{
    Raytracer::Ray ray(Math::Point3D(1, 1, 1), Math::Vector3D(2, 3, 4));

    std::cout << ray << std::endl;
    return 0;
}
