/*
** EPITECH PROJECT, 2023
** Shape/Object.cpp
** File description:
** -
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "Argument/Extern.hpp"
#include "Shape/Object.hpp"
#include "Shape/Triangle.hpp"
#include "Utility/Regex.hpp"

#define EMPTY_LINE_REGEX "^[\\t ]*(#.*)?$"
#define NEW_POINT_REGEX \
    "^\\s*v\\s+-?\\d+(|\\.\\d+)\\s+-?\\d+(|\\.\\d+)\\s+-?\\d+(|\\.\\d+)\\s*$"
#define NEW_FACE_REGEX_3 \
    "^\\s*f\\s+\\d+\\/\\d+\\/\\d+\\s+\\d+\\/\\d+\\/\\d+\\s+\\d+\\/\\d+\\/\\d+\\s*$"
#define NEW_FACE_REGEX_4 \
    "^\\s*f\\s+\\d+\\/\\d+\\/\\d+\\s+\\d+\\/\\d+\\/\\d+\\s+\\d+\\/\\d+\\/\\d+\\s+\\d+\\/\\d+\\/\\d+\\s*$"
#define POINT_IN_FACE_REGEX \
    "\\d+(?=\\/)"

static Math::Point3D readPoint(std::string const &line)
{
    std::string str;
    std::stringstream sstr(line);
    Math::Point3D point;

    sstr >> str;
    sstr >> str;
    point.x = stod(str);
    sstr >> str;
    point.y = stod(str);
    sstr >> str;
    point.z = stod(str);
    return point;
}

static Math::Point3D readPointInFace(std::string const &str, \
    std::vector<Math::Point3D> const &points)
{
    int index;

    try {
        index = \
            atoi(utility::regex::firstMatch(str, POINT_IN_FACE_REGEX).c_str());
    } catch (const std::exception &error) {
        index = -1;
    }
    if (index < 1 || static_cast<std::size_t>(index) > points.size()) {
        std::cerr << "Unknown index for index=" << index << " (size at " << \
            points.size() << ')' << std::endl;
        if (points.empty())
            return Math::Point3D();
        else
            return points.at(0);
    }
    return points.at(index - 1);
}

static void readFace3(std::string const &line, std::vector<Math::Point3D> \
    const &points, Raytracer::Texture const &texture, \
    std::list<Shape::Shape> &shapes)
{
    std::string str;
    std::stringstream sstr(line);
    Math::Point3D a, b, c;

    sstr >> str;
    sstr >> str;
    a = readPointInFace(str, points);
    sstr >> str;
    b = readPointInFace(str, points);
    sstr >> str;
    c = readPointInFace(str, points);
    shapes.push_back(Shape::createShape<Shape::Triangle>(a, b, c, texture));
}

static void readFace4(std::string const &line, std::vector<Math::Point3D> \
    const &points, Raytracer::Texture const &texture, \
    std::list<Shape::Shape> &shapes)
{
    std::string str;
    std::stringstream sstr(line);
    Math::Point3D a, b, c, d, m;

    sstr >> str;
    sstr >> str;
    a = readPointInFace(str, points);
    sstr >> str;
    b = readPointInFace(str, points);
    sstr >> str;
    c = readPointInFace(str, points);
    sstr >> str;
    d = readPointInFace(str, points);
    m = (a + b + c + d) * 0.25;
    shapes.push_back(Shape::createShape<Shape::Triangle>(a, b, m, texture));
    shapes.push_back(Shape::createShape<Shape::Triangle>(b, c, m, texture));
    shapes.push_back(Shape::createShape<Shape::Triangle>(c, d, m, texture));
    shapes.push_back(Shape::createShape<Shape::Triangle>(d, a, m, texture));
}

bool Shape::Object::_fillObject(std::string const &file, Raytracer::Texture \
    const &texture)
{
    std::ifstream stream(file);
    Math::Point3D currentPoint;
    Math::Point3D minimum;
    Math::Point3D maximum;
    bool isFirst = true;
    std::vector<Math::Point3D> points;

    if (!Arg::INPUT.noConsole)
        std::cout << "Reading '" << file << "\'..." << std::endl;
    for (std::string str; std::getline(stream, str);) {
        if (utility::regex::quickTest(str, EMPTY_LINE_REGEX))
            continue;
        if (utility::regex::quickTest(str, NEW_POINT_REGEX)) {
            currentPoint = readPoint(str) * _scale;
            if (isFirst || currentPoint.x > maximum.x)
                maximum.x = currentPoint.x;
            if (isFirst || currentPoint.y > maximum.y)
                maximum.y = currentPoint.y;
            if (isFirst || currentPoint.z > maximum.z)
                maximum.z = currentPoint.z;
            if (isFirst || currentPoint.x < minimum.x)
                minimum.x = currentPoint.x;
            if (isFirst || currentPoint.y < minimum.y)
                minimum.y = currentPoint.y;
            if (isFirst || currentPoint.z < minimum.z)
                minimum.z = currentPoint.z;
            isFirst = false;
            points.push_back(currentPoint);
            continue;
        }
        if (utility::regex::quickTest(str, NEW_FACE_REGEX_3)) {
            readFace3(str, points, texture, _shapes);
            continue;
        }
        if (utility::regex::quickTest(str, NEW_FACE_REGEX_4))
            readFace4(str, points, texture, _shapes);
    }
    _center -= (maximum - minimum) * 0.5;
    return true;
}

Shape::Object::Object(std::string const &file, Math::Point3D const center, \
    Raytracer::Texture const &texture) : Group(center)
{
    _texture = texture;
    try {
        _fillObject(file, texture);
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    };
}

Shape::Object::Object(std::string const &file, Math::Point3D const center, \
    Math::Vector3D const scale, Raytracer::Texture const &texture) : \
    Group(center)
{
    _texture = texture;
    _scale = scale;
    try {
        _fillObject(file, texture);
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    };
}
