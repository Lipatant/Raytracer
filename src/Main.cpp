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

int main(int const ac, char * const * const av)
{
    Raytracer::Ray ray;
    Raytracer::Scene scene;
    Parser::File fileScene;

    if (!Arg::INPUT.setArguments(ac, av))
        return 84;
    scene.camera.width = Arg::INPUT.width;
    scene.camera.height = Arg::INPUT.height;
    scene.camera.fov = 180;
    fileScene.parseFile(Arg::INPUT.fileScene.c_str());
    scene.shapes.splice(scene.shapes.end(), fileScene.shapes);
    scene.camera.position = fileScene.camPos;
    scene.camera.rotation = fileScene.camRot;
    if (Arg::INPUT.out.empty())
        std::cout << scene.render();
    else
        writeFile(Arg::INPUT.out, scene.render());
    return 0;
}
