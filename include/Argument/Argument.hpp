/*
** EPITECH PROJECT, 2022
** raytracer
** File description:
** Argument.h
*/

#ifndef ARGUMENT_H_
    #define ARGUMENT_H

    #include <iostream>

namespace Arg
{
    class Argument
    {
        public:
            double fov = 90;
            std::size_t width = 1920;
            std::size_t height = 1080;
            std::size_t rebound = 20;
            std::size_t blending = 1;
            void set_arguments(int, char* const*);
            Argument(void);
            ~Argument(void);
    };
}
#endif
