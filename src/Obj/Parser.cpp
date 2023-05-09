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

Parser::Model Parser::File::new_element(const libconfig::Setting& shape)
{
    Parser::Model model;
    std::string shapename;
    int tmp;

    shape.lookupValue("shape", shapename);
    model.formName = shapename;
    shape.lookupValue("x", tmp);
    model.x = tmp;
    shape.lookupValue("y", tmp);
    model.y = tmp;
    shape.lookupValue("z", tmp);
    model.z = tmp;
    shape.lookupValue("width", tmp);
    model.width = tmp;
    shape.lookupValue("height", tmp);
    model.height = tmp;
    shape.lookupValue("r", tmp);
    model.r = tmp;
    shape.lookupValue("g", tmp);
    model.g = tmp;
    shape.lookupValue("b", tmp);
    model.b = tmp;
    return model;
}

void Parser::File::generate_scene(libconfig::Config &cfg)
{
    const libconfig::Setting& s = cfg.lookup("scene.shapes");

    for (int i = 0; i < s.getLength(); ++i) {
        const libconfig::Setting& shape = s[i];
        shapes.push_back(new_element(shape));
    }
}

void Parser::File::parseFile(const char *filepath)
{
    libconfig::Config cfg;

    try {
        cfg.readFile(filepath);
    } catch(const libconfig::FileIOException &fio) {
        std::cerr << "Error reading" << std::endl;
        exit(84);
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Error parsing" << std::endl;
        exit(84);
    }
    generate_scene(cfg);
}
