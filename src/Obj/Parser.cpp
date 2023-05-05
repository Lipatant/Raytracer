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

void stockValue(std::string line) //stocker le nom de la forme x y z
{
    //std::string name, a, b, c; je suis pas sur mais je pense que ca marche
    //ss >> name >> a >> b >> c; je suis pas sur mais je pense que ca marche
    //x = stoi(a);     faire ca avec la struture
    //y = stoi(b);     faire ca avec la struture
    //z = stoi(c);     faire ca avec la struture
    //formName = name; faire ca avec la struture
}

int openFile(std::string filepath)
{
    std::ifstream file(filepath);
    std::string line = NULL;

    if (!file.is_open()) {
        std::cerr << "Error the file is not open" << std::endl;
        return 84;
    }
    if (!getline(file, line)) {
        std::cerr << "The file is empty" << std::endl;
        return 84;
    }
    while(std::getline(file, line))
        if (line[0] == '#' or line[0] == '/')
            continue;
        stockValue(line)
    file.close();
    return 0;
}
