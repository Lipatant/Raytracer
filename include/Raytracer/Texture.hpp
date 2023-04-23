/*
** EPITECH PROJECT, 2023
** Raytracer/Texture.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include "Raytracer/Color.hpp"

#define RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES 0, 0, 0, 0

namespace Raytracer {

class Texture {
public: // Main Attributes
    Raytracer::Color color;
    Raytracer::Color light;
public:
    Texture(void);
    Texture(Raytracer::Color const &color);
    Texture(Raytracer::Color const &color, Raytracer::Color const &light);
    Texture(Raytracer::Texture const &other);
    ~Texture() = default;
    //
    void operator=(Raytracer::Texture const &other);
};

};

std::ostream &operator<<(std::ostream &stream, Raytracer::Texture const \
    &texture);
