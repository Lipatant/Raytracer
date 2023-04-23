/*
** EPITECH PROJECT, 2023
** Raytracer/Color.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include "Raytracer/DisplayPixel.hpp"

namespace Raytracer {

using ColorValue = double;
static const Raytracer::ColorValue ColorValueMinimum = 0.0;
static const Raytracer::ColorValue ColorValueMaximum = 1.0;

class Color {
public: // Main Attributes
    Raytracer::ColorValue r = Raytracer::ColorValueMinimum;
    Raytracer::ColorValue g = Raytracer::ColorValueMinimum;
    Raytracer::ColorValue b = Raytracer::ColorValueMinimum;
    Raytracer::ColorValue a = Raytracer::ColorValueMaximum;
public:
    Color(void);
    Color(Raytracer::ColorValue const r, Raytracer::ColorValue const g, \
        Raytracer::ColorValue const b);
    Color(Raytracer::ColorValue const r, Raytracer::ColorValue const g, \
        Raytracer::ColorValue const b, Raytracer::ColorValue const a);
    Color(Raytracer::Color const &other);
    Color(Raytracer::Color const &other, Raytracer::ColorValue const a);
    ~Color() = default;
    //
    void operator=(Raytracer::Color const &other);
    Raytracer::Color operator*(Raytracer::ColorValue const a) const;
    Raytracer::Color operator*(Raytracer::Color const &other) const;
    void operator*=(Raytracer::ColorValue const a);
    void operator*=(Raytracer::Color const &other);
    bool operator==(Raytracer::Color const &other) const;
    bool operator!=(Raytracer::Color const &other) const;
    //
    /// @brief Converts the object to a DisplayPixel structure
    Raytracer::DisplayPixel toDisplayPixel(void) const;
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Color const \
    &color);
