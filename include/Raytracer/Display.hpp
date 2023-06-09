/*
** EPITECH PROJECT, 2023
** Raytracer/Display.hpp
** File description:
** -
*/

#pragma once
#include <iostream>
#include <memory>
#include "Raytracer/DisplayPixel.hpp"

namespace Raytracer {

class Display
{
private:
    Raytracer::DisplayPixel *_display;
    std::size_t _width;
    std::size_t _height;
    std::size_t _length;
public:
    Display(std::size_t const width, std::size_t const height);
    ~Display();
    //
    Raytracer::DisplayPixel &at(std::size_t const id);
    Raytracer::DisplayPixel &at(std::size_t const x, std::size_t const y);
    Raytracer::DisplayPixel at(std::size_t const id) const;
    Raytracer::DisplayPixel at(std::size_t const x, std::size_t const y) const;
    //
    std::size_t width(void) const;
    std::size_t height(void) const;
};

}

std::ostream &operator<<(std::ostream &stream, Raytracer::Display const \
    &display);
