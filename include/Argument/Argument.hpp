/*
** EPITECH PROJECT, 2022
** Argument/Argument.hpp
** File description:
** -
*/

#pragma once
#include <iostream>

namespace Arg {

class Argument {
public:
    bool askUsage = false;
    double fov = 90;
    bool isFovSet = false;
    std::size_t width = 680;
    std::size_t height = 400;
    std::size_t rebound = 10;
    std::size_t blending = 1;
    std::string fileScene;
    std::string out = "out.ppm";
    //
    bool alphadup = false;
    bool angularcamera = false;
    bool noConsole = false;
    //
    Argument(void);
    ~Argument(void) = default;
    //
    bool setArguments(int const, char const * const * const);
};

}
