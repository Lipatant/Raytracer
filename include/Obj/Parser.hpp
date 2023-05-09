/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Includes other includes in the Argument directory
*/

#include <iostream>
#include <map>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <libconfig.h++>

#pragma once

namespace Parser
{
    class Model
    {
    public:
        int x = 0;
        int y = 0;
        int z = 0;
        int r = 0;
        int g = 0;
        int b = 0;
        int width = 0;
        int height = 0;
        std::string formName;
        Model() = default;
        ~Model() = default;
    };
    class File {
        public:
            File();
            ~File();
            std::vector<Parser::Model> shapes;
            void parseFile(const char *);
            Parser::Model new_element(const libconfig::Setting& shape);
            void generate_scene(libconfig::Config &cfg);
    };
}

const std::map<std::string, void *> FIGURES = {
    {"sph", nullptr},
    {"tri", nullptr},
    {"pla", nullptr}
};
//string ou on envoye les forme , sph (int)x y z, tri (int)x y z, pla (int)x y z,
