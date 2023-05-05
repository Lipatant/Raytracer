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

void Parser::Model::stockValue(std::string line)
{
    std::stringstream ss(line);
    std::string tmp;

    ss >> formName;
    ss >> tmp;
    x = stoi(tmp);
    ss >> tmp;
    y = stoi(tmp);
    ss >> tmp;
    z = stoi(tmp);
    ss >> tmp;
    if (tmp.length() != 0)
        exit(84);
}

int Parser::Model::openFile(std::string filepath)
{
    std::ifstream file(filepath);
    std::string line = NULL;

    if (!file.is_open()) {
        std::cerr << "Error the file is not open" << std::endl;
        return 84;
    }
    if (!std::getline(file, line)) {
        std::cerr << "The file is empty" << std::endl;
        return 84;
    }
    while(std::getline(file, line)) {
        if (line[0] == '#' || line[0] == '/')
            continue;
        stockValue(line);
    }
    file.close();
    return 0;
}
