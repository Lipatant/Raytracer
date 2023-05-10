/*
** EPITECH PROJECT, 2023
** Raytracer/Texture.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include "Raytracer/Color.hpp"
//#include "Raytracer/TextureReflection.hpp"

#define RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES 0, 0, 0, 0

namespace Raytracer {

using TextureMirrorValue = double;
static const Raytracer::TextureMirrorValue TextureMirrorValueMinimum = 0.0;
static const Raytracer::TextureMirrorValue TextureMirrorValueMaximum = 1.0;

class Texture {
public: // Main Attributes
    Raytracer::Color color;
    Raytracer::Color light;
    double mirrorValue = Raytracer::ColorValueMinimum;
    bool isPureLight = false;
public:
    Texture(void);
    Texture(Raytracer::TextureMirrorValue const mirrorValue);
    Texture(Raytracer::Color const &color);
    Texture(Raytracer::Color const &color, Raytracer::TextureMirrorValue \
        const mirrorValue);
    Texture(Raytracer::Color const &color, Raytracer::Color const &light);
    Texture(Raytracer::Color const &color, Raytracer::Color const &light, \
        Raytracer::TextureMirrorValue const mirrorValue);
    Texture(Raytracer::Color const &color, Raytracer::Color const &light, \
        Raytracer::TextureMirrorValue const mirrorValue, \
        bool const isPureLight);
    Texture(Raytracer::Texture const &other);
    ~Texture() = default;
    //
    void operator=(Raytracer::Texture const &other);
};

};

std::ostream &operator<<(std::ostream &stream, Raytracer::Texture const \
    &texture);
