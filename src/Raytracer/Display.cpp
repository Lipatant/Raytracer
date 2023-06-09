/*
** EPITECH PROJECT, 2023
** Raytracer/Display.cpp
** File description:
** -
*/

#include "Raytracer/Display.hpp"
#include <cstring>
#include <exception>
#include <sstream>

Raytracer::Display::Display(std::size_t const width, std::size_t const height)
    : _width(width), _height(height), _length(width * height)
{
    if (_width == 0 || _length == 0)
        throw std::runtime_error( \
            "The width or length of a display should not be equal to 0");
    _display = new Raytracer::DisplayPixel[_length];
    memset(_display, 0, _length * sizeof(Raytracer::DisplayPixel));
}

Raytracer::Display::~Display()
{
    delete _display;
}

Raytracer::DisplayPixel &Raytracer::Display::at(std::size_t const id)
{
    return _display[id % _length];
}

Raytracer::DisplayPixel &Raytracer::Display::at(std::size_t const x, \
    std::size_t const y)
{
    return _display[(x + y * _width) % _length];
}

Raytracer::DisplayPixel Raytracer::Display::at(std::size_t const id) const
{
    return _display[id % _length];
}

Raytracer::DisplayPixel Raytracer::Display::at(std::size_t const x, \
    std::size_t const y) const
{
    return _display[(x + y * _width) % (_length)];
}

std::size_t Raytracer::Display::width(void) const
{
    return _width;
}

std::size_t Raytracer::Display::height(void) const
{
    return _height;
}

std::ostream &operator<<(std::ostream &stream, Raytracer::Display const \
    &display)
{
    std::size_t length = display.width() * display.height();
    Raytracer::DisplayPixel pixel;

    stream << "P6 " << display.width() << " " << display.height() << std::endl;
    stream << "255" << std::endl;
    for (std::size_t i = 0; i < length; i++) {
        pixel = display.at(i);
        stream << pixel.r << pixel.g << pixel.b;
    }
    return stream;
}
