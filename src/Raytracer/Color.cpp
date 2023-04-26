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

void Raytracer::Color::addAllColorValues(Raytracer::Color const &other)
{
    r += other.r;
    g += other.g;
    b += other.b;
    a += other.a;
}

void Raytracer::Color::blend(Raytracer::Color const &other)
{
    Raytracer::ColorValue divisor = (a + other.a == 0) ? 1 : (a + other.a);

    r = (r * a + other.r * other.a) / divisor;
    g = (g * a + other.g * other.a) / divisor;
    b = (b * a + other.b * other.a) / divisor;
    a += other.a;
}

Raytracer::Color Raytracer::Color::blended(Raytracer::Color const &other) const
{
    Raytracer::Color color(*this);

    color.blend(other);
    return color;
}

void Raytracer::Color::divideEveryColor(Raytracer::ColorValue const value)
{
    r /= value;
    g /= value;
    b /= value;
    a /= value;
}

static void normalizeColor(Raytracer::ColorValue &value)
{
    if (value > Raytracer::ColorValueMaximum)
        value = Raytracer::ColorValueMaximum;
    if (value < Raytracer::ColorValueMinimum)
        value = Raytracer::ColorValueMinimum;
}

void Raytracer::Color::normalize(void)
{
    normalizeColor(r);
    normalizeColor(g);
    normalizeColor(b);
    normalizeColor(a);
}

Raytracer::Color Raytracer::Color::normalized(void) const
{
    Raytracer::Color color(*this);

    color.normalize();
    return color;
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
