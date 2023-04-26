/*
** EPITECH PROJECT, 2023
** Raytracer/TextureReflection.hpp
** File description:
** -
*/

#pragma once
#include <iostream>

namespace Raytracer {

class TextureReflection {
public: // Main Attributes
    double normalDeformation = 0.0;
    double centering = 0.0;
    double forcedCentering = 0.0;
public:
    TextureReflection(void);
    TextureReflection(Raytracer::Color const &color);
    TextureReflection(Raytracer::Color const &color, Raytracer::Color const &light);
    TextureReflection(Raytracer::Texture const &other);
    //
    void operator=(Raytracer::TextureReflection const &other);
};

};

std::ostream &operator<<(std::ostream &stream, Raytracer::TextureReflection \
    const &texture);
