/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** Main and starting function
*/

#include <iostream>
#include "Math.hpp"
#include "Raytracer.hpp"
#include "Shape.hpp"

int main(__attribute__((unused)) int const ac, __attribute__((unused)) \
    char const * const * const av)
{
    Shape::Shape sphere1 = Shape::createShape<Shape::AShape>();

    std::cout << sphere1 << std::endl;
    return 0;
}
