/*
** EPITECH PROJECT, 2023
** Raytracer/Color/Operators.cpp
** File description:
** -
*/

#include "Raytracer/Color.hpp"

void Raytracer::Color::operator=(Raytracer::Color const &other)
{
    r = other.r; g = other.g; b = other.b; a = other.a;
}

Raytracer::Color Raytracer::Color::operator+(Raytracer::Color const &other) \
    const
{
    Raytracer::Color color = *this;

    color.r = (color.r * color.a + other.r * other.a) / (color.a + other.a);
    color.g = (color.g * color.a + other.g * other.a) / (color.a + other.a);
    color.b = (color.b * color.a + other.b * other.a) / (color.a + other.a);
    color.a += other.a;
    return color;
}

Raytracer::Color Raytracer::Color::operator*(Raytracer::Color const &other) \
    const
{
    Raytracer::Color color = *this;

    color.r *= other.r;
    color.g *= other.g;
    color.b *= other.b;
    color.a *= other.a;
    return color;
}

void Raytracer::Color::operator+=(Raytracer::Color const &other)
{
    Raytracer::ColorValue divisor = (a + other.a == 0) ? 1 : (a + other.a);

    r = (r * a + other.r * other.a) / divisor;
    g = (g * a + other.g * other.a) / divisor;
    b = (b * a + other.b * other.a) / divisor;
    a += other.a;
}

void Raytracer::Color::operator*=(Raytracer::Color const &other)
{
    r *= other.r;
    g *= other.g;
    b *= other.b;
    a *= other.a;
}

bool Raytracer::Color::operator==(Raytracer::Color const &other) const
{
    return (r == other.r && g == other.g && b == other.b && a == other.a);
}

bool Raytracer::Color::operator!=(Raytracer::Color const &other) const
{
    return (r != other.r || g != other.g || b != other.b || a != other.a);
}

Raytracer::Color Raytracer::Color::operator*(Raytracer::ColorValue const \
    alpha) const
{
    Raytracer::Color color = *this;

    color.a *= alpha;
    return color;
}

void Raytracer::Color::operator*=(Raytracer::ColorValue const alpha)
{
    a *= alpha;
}
