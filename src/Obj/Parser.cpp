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

//  dans tous
//      shape
//      x
//      y
//      z
//      soit
//          Textr
//          Textg
//          Textb
//          Texta
//      soit
//          Text1r
//          Text1g
//          Text1b
//          Text1a
//          Text2r
//          Text2g
//          Text2b
//          Text2a

//  sphere
//      idk

//  plane
//          vectx1
//          vecty1
//          vectz1
//          vectx2
//          vecty2
//          vectz2
//          idk2

//  triangle
//          x1
//          y1
//          z1
//          x2
//          y2
//          z2
//          idk2

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
