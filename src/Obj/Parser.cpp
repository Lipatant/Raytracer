#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "Obj/Parser.hpp"
#include <iostream>

static Raytracer::Texture double_rgb_texture(const libconfig::Setting& shape)
{
    double r1 = 0.0;
    double g1 = 0.0;
    double b1 = 0.0;
    double r2 = 0.0;
    double g2 = 0.0;
    double b2 = 0.0;
    double a2 = 1.0;
    double mirror = 0.0;
    std::string rgb1;
    std::string rgba2;
    std::string tmp;

    try {
        shape.lookupValue("color", rgb1);
        shape.lookupValue("light", rgba2);

        std::stringstream ss1(rgb1);
        ss1 >> tmp;
        r1 = stod(tmp);
        ss1 >> tmp;
        g1 = stod(tmp);
        ss1 >> tmp;
        b1 = stod(tmp);

        std::stringstream ss2(rgba2);
        ss2 >> tmp;
        r2 = stod(tmp);
        ss2 >> tmp;
        g2 = stod(tmp);
        ss2 >> tmp;
        b2 = stod(tmp);
        ss2 >> tmp;
        a2 = stod(tmp);

        if (shape.lookupValue("mirror", mirror))
            return Raytracer::Texture(Raytracer::Color(r1, g1, b1), Raytracer::Color(r2, g2, b2, a2), mirror);
        return Raytracer::Texture(Raytracer::Color(r1, g1, b1), Raytracer::Color(r2, g2, b2, a2));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return Raytracer::Texture();
}

static Raytracer::Texture simple_rgb_texture(std::string rgb, const libconfig::Setting& shape)
{
    double r;
    double g;
    double b;
    double mirror;
    std::string tmp;
    std::stringstream ss(rgb);
    try {
        ss >> tmp;
        r = stod(tmp);
        ss >> tmp;
        g = stod(tmp);
        ss >> tmp;
        b = stod(tmp);
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return Raytracer::Texture();
    }
    if (shape.lookupValue("mirror", mirror))
        return Raytracer::Texture(Raytracer::Color(r, g, b), mirror);
    return Raytracer::Texture(Raytracer::Color(r, g, b));
}

static Raytracer::Texture simple_rgba_texture(std::string rgb, const libconfig::Setting& shape)
{
    double r;
    double g;
    double b;
    double a;
    double mirror;
    std::string tmp;
    std::stringstream ss(rgb);
    try {
        ss >> tmp;
        r = stod(tmp);
        ss >> tmp;
        g = stod(tmp);
        ss >> tmp;
        b = stod(tmp);
        ss >> tmp;
        a = stod(tmp);
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return Raytracer::Texture();
    }
    if (shape.lookupValue("mirror", mirror))
        return Raytracer::Texture(Raytracer::Color(r, g, b, a), mirror);
    return Raytracer::Texture(Raytracer::Color(r, g, b, a));
}

static Raytracer::Texture generate_texture(const libconfig::Setting& shape)
{
    std::string type_text;

    if (shape.lookupValue("rgb", type_text))
        return simple_rgb_texture(type_text, shape);
    else if (shape.lookupValue("rgba", type_text))
        return simple_rgba_texture(type_text, shape);
    return double_rgb_texture(shape);
}

static void create_sphere(Parser::File& file, const libconfig::Setting& shape)
{
    double radius;

    try {
    shape.lookupValue("radius", radius);
    file.shapes.push_back(Shape::createShape<Shape::Sphere>( \
        Math::Point3D(file.x,file.y,file.z), radius, generate_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        file.shapes.push_back(Shape::createShape<Shape::Sphere>( \
            Math::Point3D(), 0, Raytracer::Texture()));
    }
}

static void create_triangle(Parser::File& file, const libconfig::Setting& shape)
{
    int x1;
    int y1;
    int z1;
    int x2;
    int y2;
    int z2;
    try {
    shape.lookupValue("x1", x1);
    shape.lookupValue("y1", y1);
    shape.lookupValue("z1", z1);
    shape.lookupValue("x2", x2);
    shape.lookupValue("y2", y2);
    shape.lookupValue("z2", z2);
    file.shapes.push_back(Shape::createShape<Shape::Triangle>( \
        Math::Point3D(file.x,file.y,file.z), Math::Point3D(x1, y1, z1), Math::Point3D(x2,y2,z2), \
        generate_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        file.shapes.push_back(Shape::createShape<Shape::Triangle>( \
            Math::Point3D(), Math::Point3D(), Math::Point3D(), Raytracer::Texture()));
    }
}

static void create_plane(Parser::File& file, const libconfig::Setting& shape)
{
    int vectx1;
    int vecty1;
    int vectz1;
    int vectx2;
    int vecty2;
    int vectz2;
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
            generate_texture(shape)));
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        file.shapes.push_back((Shape::createShape<Shape::Plane>( \
            Math::Point3D(), Math::Vector3D(), Math::Vector3D(), Raytracer::Texture())));
    }
}

const std::map<std::string, void (*)(Parser::File&, const libconfig::Setting&)> FIGURES = {
    {"sphere", create_sphere},
    {"triangle", create_triangle},
    {"plane", create_plane},
};

void Parser::File::new_element(const libconfig::Setting& s)
{
    s.lookupValue("shape", shapename);
    s.lookupValue("x", x);
    s.lookupValue("y", y);
    s.lookupValue("z", z);
    if (FIGURES.find(shapename) == FIGURES.end()) {
        std::cerr << "unknown shape: " << shapename << std::endl;
        exit(84);
    }
    FIGURES.at(shapename)(*this, s);
}

void Parser::File::manage_camera(const libconfig::Setting& c)
{
    double posx;
    double posy;
    double posz;
    int angle1;
    int angle2;
    int f;

    try {
        c.lookupValue("posx", posx);
        c.lookupValue("posy", posy);
        c.lookupValue("posz", posz);
        c.lookupValue("angle1", angle1);
        c.lookupValue("angle2", angle2);
        camPos = Math::Point3D(posx, posy, posz);
        camRot = Math::Angle3D(angle1, angle2);
    } catch (const std::exception& e) {
        camPos = Math::Point3D();
        camRot = Math::Angle3D();
    }
    if (c.lookupValue("fov", f))
        fov = f;
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
        cfg.readFile(filepath);
    } catch(const libconfig::FileIOException &fio) {
        std::cerr << "Error reading: " << std::endl;
        exit(84);
    } catch(const libconfig::ParseException &pex) {
        std::cerr << "Error parsing at line " << pex.getLine() << ": " << pex.getError() << std::endl;
        exit(84);
    }
    generate_scene(cfg);
}
