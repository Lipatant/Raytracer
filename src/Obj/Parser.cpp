/*
** EPITECH PROJECT, 2023
** Obj/Parser.cpp
** File description:
** -
*/

#include <fstream>
#include <sstream>
#include <string>
#include "../include/Obj/Parser.hpp"

void stockValue(void) //stocker le nom de la forme x y z
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
    while(std::getline(file, line))
        std::string name, a, b, c;
        ss >> name >> a >> b >> c;
        Model.x = stoi(a);
        Model.y = stoi(b);
        Model.z = stoi(c);
        Model.formName = name;
    file.close;
    return 0;
}

//sphère xyz, un double, texture(rgb, rgba)
//triangle
//plane
//angle cam