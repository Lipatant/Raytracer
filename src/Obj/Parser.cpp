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

void Parser::File::new_element(const libconfig::Setting& shape)
{
//    shape.lookupValue("shape", model.formName);
}

void Parser::File::generate_scene(libconfig::Config &cfg)
{
    const libconfig::Setting& s = cfg.lookup("scene.shapes");

    for (int i = 0; i < s.getLength(); ++i) {
        const libconfig::Setting& shape = s[i];
        new_element(shape);
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
