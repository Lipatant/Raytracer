/*
** EPITECH PROJECT, 2023
** Main.cpp
** File description:
** Main and starting function
*/

#include <exception>
#include <fstream>
#include <iostream>
#include "Argument.hpp"
#include "Math.hpp"
#include "Raytracer.hpp"
#include "Shape.hpp"
#include "Obj/Parser.hpp"

#define DEFAULT_MIRROR_CUBE 0.98 // 0.98

Arg::Argument Arg::INPUT;

static void writeFile(std::string const &filepath, Raytracer::Display const \
    &display)
{
    std::ofstream file;

    file.open(filepath);
    if (!file)
        throw std::runtime_error("Couldn't open a file");
    file << display;
    file.close();
}

static int displayUsage(std::ostream &stream)
{
    stream << "USAGE:" << std::endl;
    stream << "\t./raytracer <SCENE_FILE>/-h [...]" << std::endl;
    stream << std::endl;
    stream << "\tSCENE_FILE: scene configuration" << std::endl;
    stream << "\t-h / --help: display usage" << std::endl;
    stream << std::endl;
    stream << "For more options, check README.md" << std::endl;
    return 0;
}

int main(int const ac, char * const * const av)
{
    Raytracer::Ray ray;
    Raytracer::Scene scene;
    Parser::File fileScene;

    if (!Arg::INPUT.setArguments(ac, av))
        return 84;
    if (Arg::INPUT.askUsage)
        return displayUsage(std::cout);
    fileScene.parseFile(Arg::INPUT.fileScene.c_str());
    Arg::INPUT.skybox = fileScene.skybox;
    scene.camera.width = Arg::INPUT.width;
    scene.camera.height = Arg::INPUT.height;
    if (Arg::INPUT.isFovSet)
        scene.camera.fov = Arg::INPUT.fov;
    else
        scene.camera.fov = fileScene.fov;
    scene.shapes.splice(scene.shapes.end(), fileScene.shapes);
    scene.camera.position = fileScene.camPos;
    scene.camera.rotation = fileScene.camRot;
    if (Arg::INPUT.out.empty())
        std::cout << scene.render();
    else
        writeFile(Arg::INPUT.out, scene.render());
    return 0;
}
