/*
** EPITECH PROJECT, 2023
** Shape/AShape.hpp
** File description:
** -
*/

#pragma once
#include "Shape/IShape.hpp"

#define SHAPE_ASHAPE_DEFAULT_NAME "UnknownShape"

namespace Shape {

class AShape : public IShape
{
protected:
    Raytracer::Texture _texture;
    std::string _name = SHAPE_ASHAPE_DEFAULT_NAME;
    bool _isPureLight = false;
public:
    AShape(void);
    AShape(std::string const &name);
    AShape(Raytracer::Texture const &texture);
    AShape(std::string const &name, Raytracer::Texture const &texture);
    //
    bool hits(Raytracer::Ray const &ray) const override;
    Raytracer::HitPointList hitPoints(Raytracer::Ray const &ray) const \
        override;
    //
    Math::Point3D getCenter(void) const override;
    //
    Raytracer::Texture texture(void) final;
    Raytracer::Texture texture(void) const final;
    std::string name(void) const final;
    bool isPureLight(void) const final;
};

}
