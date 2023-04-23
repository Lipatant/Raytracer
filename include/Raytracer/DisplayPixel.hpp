/*
** EPITECH PROJECT, 2023
** Raytracer/DisplayPixel.hpp
** File description:
** -
*/

#pragma once
#include <iostream>

namespace Raytracer {

using DisplayPixelValue = std::uint8_t;

static const std::size_t DisplayPixelValueDifferents = 256;
static const Raytracer::DisplayPixelValue DisplayPixelValueMinimum = 0;
static const Raytracer::DisplayPixelValue DisplayPixelValueMaximum = 255;

struct DisplayPixel_s {
    Raytracer::DisplayPixelValue r;
    Raytracer::DisplayPixelValue g;
    Raytracer::DisplayPixelValue b;
    Raytracer::DisplayPixelValue a;
};

using DisplayPixel = struct DisplayPixel_s;

}
