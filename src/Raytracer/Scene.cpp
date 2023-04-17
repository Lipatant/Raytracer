/*
** EPITECH PROJECT, 2023
** Raytracer/Scene.cpp
** File description:
** -
*/

#include "Raytracer/Scene.hpp"

std::ostream &operator<<(std::ostream &stream, Raytracer::Scene const &scene)
{
    stream << "Camera:" << std::endl << scene.camera << std::endl;
    stream << "Shapes:" << std::endl;
    for (auto const &shape : scene.shapes)
        stream << shape << std::endl;;
    return stream;
}
