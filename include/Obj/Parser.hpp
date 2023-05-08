/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Includes other includes in the Argument directory
*/

#include <iostream>
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
        void stockValue(std::string line);
    };
    class File {
        public:
            File();
            ~File();
            std::vector<Parser::Model> shapes;
            void openFile(std::string);
    };
}
//string ou on envoye les forme , sph (int)x y z, tri (int)x y z, pla (int)x y z,
