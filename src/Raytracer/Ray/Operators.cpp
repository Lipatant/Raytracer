/*
** EPITECH PROJECT, 2023
** Raytracer/Ray/Operators.cpp
** File description:
** -
*/

#include "Raytracer/Ray.hpp"

void Raytracer::Ray::operator=(Ray const &other)
{
    origin = other.origin;
}

Raytracer::Ray Raytracer::Ray::operator+(Ray const &other) const
{
    return Raytracer::Ray(origin, direction + other.direction);
}

Raytracer::Ray Raytracer::Ray::operator-(Ray const &other) const
{
    return Raytracer::Ray(origin, direction - other.direction);
}

Raytracer::Ray Raytracer::Ray::operator*(Ray const &other) const
{
    return Raytracer::Ray(origin, direction * other.direction);
}

Raytracer::Ray Raytracer::Ray::operator/(Ray const &other) const
{
    return Raytracer::Ray(origin, direction / other.direction);
}

void Raytracer::Ray::operator+=(Ray const &other)
{
    direction += other.direction;
}

void Raytracer::Ray::operator-=(Ray const &other)
{
    direction -= other.direction;
}

void Raytracer::Ray::operator*=(Ray const &other)
{
    direction *= other.direction;
}

void Raytracer::Ray::operator/=(Ray const &other)
{
    direction /= other.direction;
}

bool Raytracer::Ray::operator==(Ray const &other) const
{
    return (direction == other.direction);
}

bool Raytracer::Ray::operator!=(Ray const &other) const
{
    return (direction != other.direction);
}
