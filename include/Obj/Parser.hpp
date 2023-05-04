/*
** EPITECH PROJECT, 2023
** Parser.hpp
** File description:
** Includes other includes in the Argument directory
*/

#include <iostream>

#pragma once

namespace Parser
{
    class Model
    {
    private:
        int x = 0;
        int y = 0;
        int z = 0;
        std::string formName;
    public:
        Model() = default;
        ~Model() = default;
        openFile(std::string);
    };
}

//string ou on envoye les forme , sph (int)x y z, tri (int)x y z, pla (int)x y z,
