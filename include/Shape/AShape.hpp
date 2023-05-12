/*
** EPITECH PROJECT, 2023
** Shape/AShape.hpp
** File description:
** -
*/

#pragma once
#include "Shape/IShape.hpp"

#define SHAPE_ASHAPE_DEFAULT_NAME "UnknownShape"

#define SHAPE_DEFAULT_SCALE_VALUES 1, 1, 1

namespace Shape {

class AShape : public IShape
{
protected:
    Raytracer::Texture _texture;
    Math::Vector3D _scale = Math::Vector3D(SHAPE_DEFAULT_SCALE_VALUES);
    //
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
    Raytracer::HitPointList computeHitPoints(Raytracer::Ray const &ray) const \
        final;
    Raytracer::HitPointList computeHitPoints(Raytracer::Ray const &ray, \
        Math::Vector3D additionalScale) const final;
    //
    Math::Point3D getCenter(void) const override;
    Math::Vector3D &getScale(void) final;
    Math::Vector3D getScale(void) const final;
    //
    Raytracer::Texture texture(void) final;
    Raytracer::Texture texture(void) const final;
    std::string name(void) const final;
    bool isPureLight(void) const final;
};

}
