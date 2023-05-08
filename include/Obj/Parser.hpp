/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Includes other includes in the Argument directory
*/

#include <iostream>
#include <map>
#include <vector>

#pragma once

namespace Parser
{
    class Model
    {
    public:
        int x = 0;
        int y = 0;
        int z = 0;
        std::string formName;
    public:
        Model() = default;
        ~Model() = default;
        void stockValue(const std::string);
    };
    class File {
        public:
            File();
            ~File();
            std::vector<Parser::Model> shapes;
            void parseFile(const std::string);
    };
}

const std::map<std::string, void *> FIGURES = {
    {"sph", nullptr},
    {"tri", nullptr},
    {"pla", nullptr}
};
//string ou on envoye les forme , sph (int)x y z, tri (int)x y z, pla (int)x y z,
