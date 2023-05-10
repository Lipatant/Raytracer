/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Includes other includes in the Argument directory
*/

#include <iostream>
#include <map>
#include "Shape.hpp"
#include <iostream>
#include <stdlib.h>
#include <libconfig.h++>

#pragma once

namespace Parser
{
    class Sphere {
        double idk;
        Sphere(){}
        ~Sphere(){}
    };
    class Triangle {
        int x1;
        int y1;
        int z1;
        int x2;
        int y2;
        int z2;
        double idk2;
        Triangle(){}
        ~Triangle(){}
    };
    class Plane {
        int vectx1;
        int vecty1;
        int vectz1;
        int vectx2;
        int vecty2;
        int vectz2;
        double idk2;
        Plane(){}
        ~Plane(){}
    };
    class File {
        public:
            std::string shape;
            int x;
            int y;
            int z;
            double Textr = 0;
            double Textg = 0;
            double Textb = 0;
            double Texta = 1.0;
            double Text1r = 0;
            double Text1g = 0;
            double Text1b = 0;
            double Text1a = 1.0;
            double Text2r = 0;
            double Text2g = 0;
            double Text2b = 0;
            double Text2a = 0.0;
            File();
            ~File();
            std::list<Shape::Shape> shapes;
            void parseFile(const char *);
            void new_element(const libconfig::Setting& shape);
            void generate_scene(libconfig::Config &cfg);
    };
}

const std::map<std::string, void *> FIGURES = {
    {"sph", nullptr},
    {"tri", nullptr},
    {"pla", nullptr}
};
