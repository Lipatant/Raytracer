/*
** EPITECH PROJECT, 2023
** Obj/Parser.cpp
** File description:
** -
*/

#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include "Obj/Parser.hpp"
#include "Utility/Regex.hpp"

#define COLOR_RGB_REGEX \
    "^\\s*-?\\d+(|\\.\\d+)\\s+-?\\d(|\\.\\d+)\\s+-?\\d(|\\.\\d+)\\s*$"
#define COLOR_RGBA_REGEX \
    "^\\s*-?\\d+(|\\.\\d+)\\s+-?\\d(|\\.\\d+)\\s+-?\\d(|\\.\\d+)\\s+\\d(|\\.\\d+)\\s*$"
#define VECTOR_REGEX \
    "^\\s*-?\\d+(|\\.\\d+)\\s+-?\\d(|\\.\\d+)\\s+-?\\d(|\\.\\d+)\\s*$"
#define DOUBLE_REGEX \
    "^\\s*-?\\d+(|\\.\\d+)\\s*$"

static bool get_vector(std::string const &str, Math::Vector3D &vector)
{
    std::string tmp;

    if (utility::regex::quickTest(str, VECTOR_REGEX)) {
        std::stringstream ss1(str);
        ss1 >> tmp;
        vector.x = stod(tmp);
        ss1 >> tmp;
        vector.y = stod(tmp);
        ss1 >> tmp;
        vector.z = stod(tmp);
        return true;
    }
    if (utility::regex::quickTest(str, DOUBLE_REGEX)) {
        std::stringstream ss1(str);
        ss1 >> tmp;
        vector.x = stod(tmp);
        vector.y = vector.x;
        vector.z = vector.x;
        return true;
    }
    return false;
}

static bool get_color(std::string const &str, Raytracer::Color &color)
{
    std::string tmp;

    if (utility::regex::quickTest(str, COLOR_RGB_REGEX)) {
        std::stringstream ss1(str);
        ss1 >> tmp;
        color.r = stod(tmp);
        ss1 >> tmp;
        color.g = stod(tmp);
        ss1 >> tmp;
        color.b = stod(tmp);
        color.a = Raytracer::ColorValueMaximum;
        return true;
    }
    if (utility::regex::quickTest(str, COLOR_RGBA_REGEX)) {
        std::stringstream ss1(str);
        ss1 >> tmp;
        color.r = stod(tmp);
        ss1 >> tmp;
        color.g = stod(tmp);
        ss1 >> tmp;
        color.b = stod(tmp);
        ss1 >> tmp;
        color.a = stod(tmp);
        return true;
    }
    return false;
}

static Raytracer::Texture double_rgb_texture(const libconfig::Setting& shape)
{
    std::string str;
    std::string tmp;
    Raytracer::Color color;
    Raytracer::Color light(RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES);
    Raytracer::TextureMirrorValue mirror = \
        RAYTRACER_TEXTURE_MIRROR_VALUE_DEFAULT;

    try {
        if (shape.lookupValue("color", str))
            if (!get_color(str, color))
                std::cerr << "Couldn't parse '" << str << "' as a color" << std::endl;
        if (shape.lookupValue("light", str))
            if (!get_color(str, light))
                std::cerr << "Couldn't parse '" << str << "' as a light" << std::endl;
        shape.lookupValue("mirror", mirror);
        return Raytracer::Texture(color, light, mirror);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return Raytracer::Texture(color, light, mirror);
}

static Raytracer::Color simple_rgb_texture(const libconfig::Setting& shape)
{
    std::string str;
    std::string tmp;
    Raytracer::Color color;

    try {
        if (shape.lookupValue("color", str))
            if (!get_color(str, color))
                std::cerr << "Couldn't parse '" << str << "' as a color/light" << std::endl;
        if (shape.lookupValue("light", str))
            if (!get_color(str, color))
                std::cerr << "Couldn't parse '" << str << "' as a color/light" << std::endl;
        return color;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return color;
}

static bool create_object(Parser::File& file, const libconfig::Setting& shape)
{
    std::string str;

    try {
        if (!shape.lookupValue("file", str)) {
            std::cerr << "'file' attribute no found inside for a Shape::Object" << std::endl;
            return false;
        }
        file.shapes.push_back(Shape::createShape<Shape::Object>( \
            str, Math::Point3D(file.x,file.y,file.z), file.scale, \
            double_rgb_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}

static bool create_sphere(Parser::File& file, const libconfig::Setting& shape)
{
    double radius = 1.0;

    try {
    shape.lookupValue("radius", radius);
    file.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(file.x,file.y,file.z), radius, double_rgb_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        file.shapes.push_back(Shape::createShape<Shape::Sphere>( \
            Math::Point3D(), 0, Raytracer::Texture()));
    }
    return true;
}

static bool create_triangle(Parser::File& file, const libconfig::Setting& shape)
{
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    try {
        shape.lookupValue("x1", x1);
        shape.lookupValue("y1", y1);
        shape.lookupValue("z1", z1);
        shape.lookupValue("x2", x2);
        shape.lookupValue("y2", y2);
        shape.lookupValue("z2", z2);
        file.shapes.push_back(Shape::createShape<Shape::Triangle>( \
            Math::Point3D(file.x,file.y,file.z), Math::Point3D(x1, y1, z1), Math::Point3D(x2,y2,z2), \
            double_rgb_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        file.shapes.push_back(Shape::createShape<Shape::Triangle>( \
            Math::Point3D(), Math::Point3D(), Math::Point3D(), Raytracer::Texture()));
    }
    return true;
}

static bool create_plane(Parser::File& file, const libconfig::Setting& shape)
{
    double vectx1;
    double vecty1;
    double vectz1;
    double vectx2;
    double vecty2;
    double vectz2;
    try {
        shape.lookupValue("vectx1", vectx1);
        shape.lookupValue("vecty1", vecty1);
        shape.lookupValue("vectz1", vectz1);
        shape.lookupValue("vectx2", vectx2);
        shape.lookupValue("vecty2", vecty2);
        shape.lookupValue("vectz2", vectz2);
        file.shapes.push_back(Shape::createShape<Shape::Plane>( \
            Math::Point3D(file.x,file.y,file.z),
            Math::Vector3D(vectx1,vecty1,vectz1),
            Math::Vector3D(vectx2,vecty2,vectz2),
            double_rgb_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        file.shapes.push_back((Shape::createShape<Shape::Plane>( \
            Math::Point3D(), Math::Vector3D(), Math::Vector3D(), Raytracer::Texture())));
    }
    return true;
}

static bool create_ambiant_light(Parser::File& file, const libconfig::Setting& shape)
{
    file.shapes.push_back(Shape::createShape<Shape::AmbientLight>(Math::Point3D(file.x,file.y,file.z), simple_rgb_texture(shape)));
    return true;
}

static bool create_directional_light(Parser::File& file, const libconfig::Setting& shape)
{
    std::string str;
    Math::Vector3D direction(0, 0, -1);
    Shape::DirectionalLightFOI foi = 90;

    try {
        if (shape.lookupValue("direction", str))
            if (!get_vector(str, direction))
                std::cerr << "Couldn't parse '" << str << "' as a vector" << std::endl;
        shape.lookupValue("foi", foi);
        file.shapes.push_back(Shape::createShape<Shape::DirectionalLight>(Math::Point3D(file.x,file.y,file.z), direction, foi, simple_rgb_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        file.shapes.push_back((Shape::createShape<Shape::Plane>( \
            Math::Point3D(), Math::Vector3D(), Math::Vector3D(), Raytracer::Texture())));
    }
    return true;
}

static bool create_group(Parser::File& file, const libconfig::Setting& shape)
{
    const libconfig::Setting& sList = shape.lookup("shapes");
    Parser::File newFile;

    try {
        for (int i = 0; i < sList.getLength(); ++i) {
            const libconfig::Setting& newShape = sList[i];
            newFile.new_element(newShape);
        }
        file.shapes.push_back(Shape::createShape<Shape::Group>( \
            Math::Point3D(file.x, file.y, file.z), newFile.shapes));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        file.shapes.push_back(Shape::createShape<Shape::Group>(Math::Point3D \
            (file.x, file.y, file.z)));
    }
    return true;
}

const std::map<std::string, bool (*)(Parser::File&, const libconfig::Setting&)> FIGURES = {
    {"sphere", create_sphere},
    {"triangle", create_triangle},
    {"plane", create_plane},
    {"ambiant_light", create_ambiant_light},
    {"ambiantLight", create_ambiant_light},
    {"ambiant", create_ambiant_light},
    {"light", create_ambiant_light},
    {"directionalLight", create_directional_light},
    {"directional_light", create_directional_light},
    {"directional", create_directional_light},
    {"group", create_group},
    {"file", create_object},
    {"object", create_object},
};

void Parser::File::new_element(const libconfig::Setting& s)
{
    std::string str;
    bool hasScale = false;
    Shape::Shape shape;
    double scaleSingle;

    x = 0; y = 0; z = 0;
    scale = Math::Vector3D(1, 1, 1);
    s.lookupValue("shape", shapename);
    s.lookupValue("x", x);
    s.lookupValue("y", y);
    s.lookupValue("z", z);
    if (s.lookupValue("scale", str)) {
        if (!get_vector(str, scale))
            std::cerr << "Couldn't parse '" << str << "' as a scaling vector" << std::endl;
        else
            hasScale = true;
    } else if (s.lookupValue("scale", scaleSingle)) {
        scale.x = scaleSingle;
        scale.y = scaleSingle;
        scale.z = scaleSingle;
        hasScale = true;
    }
    if (FIGURES.find(shapename) == FIGURES.end()) {
        std::cerr << "unknown shape: " << shapename << std::endl;
        exit(84);
    }
    if (!FIGURES.at(shapename)(*this, s))
        return;
    if (hasScale)
        shapes.back()->getScale() = scale;
}

void Parser::File::manage_camera(const libconfig::Setting& c)
{
    double posx;
    double posy;
    double posz;
    double angle1;
    double angle2;
    double f;
    std::string str;
    Raytracer::Color light(RAYTRACER_TEXTURE_LIGHT_DEFAULT_VALUES);

    try {
        c.lookupValue("posx", posx);
        c.lookupValue("posy", posy);
        c.lookupValue("posz", posz);
        c.lookupValue("angle1", angle1);
        c.lookupValue("angle2", angle2);
        if (c.lookupValue("color", str))
            if (!get_color(str, light))
                std::cerr << "Couldn't parse '" << str << "' as a light" << std::endl;
        if (c.lookupValue("sky", str))
            if (!get_color(str, light))
                std::cerr << "Couldn't parse '" << str << "' as a light" << std::endl;
        if (c.lookupValue("skybox", str))
            if (!get_color(str, light))
                std::cerr << "Couldn't parse '" << str << "' as a light" << std::endl;
        camPos = Math::Point3D(posx, posy, posz);
        camRot = Math::Angle3D(angle1, angle2);
    } catch (const std::exception& e) {
        camPos = Math::Point3D();
        camRot = Math::Angle3D();
    }
    if (c.lookupValue("fov", f))
        fov = f;
    skybox = light;
}

void Parser::File::generate_scene(libconfig::Config &cfg)
{
    const libconfig::Setting& s = cfg.lookup("scene.shapes");
    const libconfig::Setting& c = cfg.lookup("scene.camera");

    for (int i = 0; i < s.getLength(); ++i) {
        const libconfig::Setting& shape = s[i];
        new_element(shape);
    }
    manage_camera(c);
}

void Parser::File::parseFile(const char *filepath)
{
    libconfig::Config cfg;

    try {
        cfg.setAutoConvert(true);
        cfg.readFile(filepath);
    } catch(const libconfig::FileIOException &fio) {
        std::cerr << "Error reading: " << fio.what() << std::endl;
        exit(84);
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Error parsing at line " << pex.getLine() << ": " << pex.getError() << std::endl;
        exit(84);
    }
    generate_scene(cfg);
}
