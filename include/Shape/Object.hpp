/*
** EPITECH PROJECT, 2023
** Shape/Object.hpp
** File description:
** -
*/

#pragma once
#include "Shape/Group.hpp"

namespace Shape {

class Object : public Group
{
private:
    bool _fillObject(std::string const &file, Raytracer::Texture const \
        &texture);
public:
    Object(std::string const &file, Math::Point3D const center, \
        Raytracer::Texture const &texture);
    Object(std::string const &file, Math::Point3D const center, \
        Math::Vector3D const scale, Raytracer::Texture const &texture);
};

}
