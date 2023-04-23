/*
** EPITECH PROJECT, 2023
** Raytracer/Color/Constructors.cpp
** File description:
** -
*/

#include "Raytracer/Color.hpp"

Raytracer::Color::Color(void)
{ }

Raytracer::Color::Color(Raytracer::ColorValue const r, Raytracer::ColorValue \
    const g, Raytracer::ColorValue const b) : r(r), g(g), b(b)
{ }

Raytracer::Color::Color(Raytracer::ColorValue const r, Raytracer::ColorValue \
    const g, Raytracer::ColorValue const b, Raytracer::ColorValue const a) :
    r(r), g(g), b(b), a(a)
{ }

Raytracer::Color::Color(Raytracer::Color const &other) :
    r(other.r), g(other.g), b(other.b), a(other.a)
{ }

Raytracer::Color::Color(Raytracer::Color const &other, Raytracer::ColorValue \
    const a) : r(other.r), g(other.g), b(other.b), a(a)
{ }
