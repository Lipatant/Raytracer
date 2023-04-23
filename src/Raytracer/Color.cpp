/*
** EPITECH PROJECT, 2023
** Raytracer/Color.cpp
** File description:
** -
*/

#include "Raytracer/Color.hpp"

Raytracer::DisplayPixel Raytracer::Color::toDisplayPixel(void) const
{
    Raytracer::DisplayPixel displayPixel;

    displayPixel.r = static_cast<Raytracer::DisplayPixelValue>(r * \
        Raytracer::DisplayPixelValueMaximum);
    displayPixel.g = static_cast<Raytracer::DisplayPixelValue>(g * \
        Raytracer::DisplayPixelValueMaximum);
    displayPixel.b = static_cast<Raytracer::DisplayPixelValue>(b * \
        Raytracer::DisplayPixelValueMaximum);
    displayPixel.a = static_cast<Raytracer::DisplayPixelValue>(a * \
        Raytracer::DisplayPixelValueMaximum);
    return displayPixel;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Color const &color)
{
    stream << "c(" << color.r << '|' << color.g << '|' << color.b << '|' << \
        color.a << ')';
    return stream;
}
