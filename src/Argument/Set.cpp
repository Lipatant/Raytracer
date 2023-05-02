/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Set.cpp
*/

#include "Argument/Argument.hpp"
#include <iostream>
#include <cassert>
#include <string>

void Arg::Argument::set_arguments(int ac, char *const *av)
{
    std::string tag;

    try
    {
        for (int i = 1; i < ac; i += 2)
        {
            tag = av[i];
            if (tag == "-f")
                fov = std::stod(av[i + 1]);
            else if (tag == "-w")
                width = std::stoul(av[i + 1]);
            else if (tag == "-h")
                height = std::stoul(av[i + 1]);
            else if (tag == "-r")
                rebound = std::stoul(av[i + 1]);
            else if (tag == "-b")
                blending = std::stoul(av[i + 1]);
        }
    } catch (const std::exception &error) {
        std::cerr << "Error: " << error.what() << std::endl;
        exit(84);
    }
}
