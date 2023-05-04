/*
** EPITECH PROJECT, 2023
** Obj/Parser.cpp
** File description:
** -
*/

#include <fstream>
#include "../include/Obj/Parser.hpp"

void stockValue() //stocker le nom de la forme x y z
{
    return;
}

int openFile(std::string filepath)
{
    std::ifstream file(filepath);
    std::string line = NULL;

    if (!file.is_open()) {
        std::cerr << "Error the file is not open" << std::endl;
        return 84;
    }
    while(std::getline(file, line))     //modifié ca parce que ca print ca fait que print
        std::cout << line << std::endl; //modifié ca parce que ca print ca fait que print
    file.close;
    return 0;
}

//sphère xyz, un double, texture(rgb, rgba)
//triangle
//plane
//angle cam