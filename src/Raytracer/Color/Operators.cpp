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

    color.r += other.r;
    color.g += other.g;
    color.b += other.b;
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
    r += other.r;
    g += other.g;
    b += other.b;
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

Raytracer::Color Raytracer::Color::operator/(Raytracer::ColorValue const \
    alpha) const
{
    Raytracer::Color color = *this;

    color.a /= alpha;
    return color;
}

void Raytracer::Color::operator*=(Raytracer::ColorValue const alpha)
{
    a *= alpha;
}

void Raytracer::Color::operator/=(Raytracer::ColorValue const alpha)
{
    a /= alpha;
}
