/*
** EPITECH PROJECT, 2023
** Raytracer/Color.cpp
** File description:
** -
*/

#include "Raytracer/Color.hpp"

static Raytracer::DisplayPixelValue _colorToDisplayPixelValue( \
    Raytracer::ColorValue const value)
{
    if (value <= Raytracer::ColorValueMinimum)
        return Raytracer::DisplayPixelValueMinimum;
    if (value >= Raytracer::ColorValueMaximum)
        return Raytracer::DisplayPixelValueMaximum;
    return static_cast<Raytracer::DisplayPixelValue>((value * \
        Raytracer::DisplayPixelValueMaximum) / Raytracer::ColorValueMaximum);
}

Raytracer::DisplayPixel Raytracer::Color::toDisplayPixel(void) const
{
    Raytracer::DisplayPixel displayPixel;

    displayPixel.r = _colorToDisplayPixelValue(r);
    displayPixel.g = _colorToDisplayPixelValue(g);
    displayPixel.b = _colorToDisplayPixelValue(b);
    displayPixel.a = _colorToDisplayPixelValue(a);
    return displayPixel;
}

Raytracer::Color Raytracer::Color::withoutAlpha(void) const
{
    Raytracer::Color color(*this);

    color.r *= color.a;
    color.g *= color.a;
    color.b *= color.a;
    color.a = Raytracer::ColorValueMaximum;
    return color;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Color const &color)
{
    stream << "c(" << color.r << '|' << color.g << '|' << color.b << '|' << \
        color.a << ')';
    return stream;
}
