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
    class File {
        public:
            std::string shape;
            int x;
            int y;
            int z;
//      soit
//          Textr
//          Textg
//          Textb
//          Texta
//      soit
//          Text1r
//          Text1g
//          Text1b
//          Text1a
//          Text2r
//          Text2g
//          Text2b
//          Text2a
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
//string ou on envoye les forme , sph (int)x y z, tri (int)x y z, pla (int)x y z,
