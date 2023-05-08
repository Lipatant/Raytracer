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

Parser::File::File(void)
{

}

Parser::File::~File(void)
{

}

void Parser::Model::stockValue(const std::string line)
{
    if (line.empty()) {
        std::cerr << "Error: empty line passed to stockValue" << std::endl;
        return;
    }
    std::stringstream ss(line);
    std::string tmp;

    ss >> formName;
    if (FIGURES.find(formName) == FIGURES.end()) {
        std::cerr << "Error: invalid value in file: " << formName << std::endl;
        exit(84);
    }
    ss >> tmp;
    x = stoi(tmp);
    ss >> tmp;
    y = stoi(tmp);
    ss >> tmp;
    z = stoi(tmp);
}

static Parser::Model new_element(const std::string line)
{
    Parser::Model newmodel;

    newmodel.stockValue(line);
    return newmodel;
}

void Parser::File::parseFile(const std::string filepath)
{
    std::ifstream file(filepath);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: the file is not open" << std::endl;
        return;
    }
    if (!std::getline(file, line)) {
        std::cerr << "Error: the file is empty" << std::endl;
        return;
    }
    shapes.push_back(new_element(line));
    while(std::getline(file, line)) {
        if (line.empty() || line[0] == '#' || line[0] == '/')
            continue;
        shapes.push_back(new_element(line));
    }
    file.close();
}
