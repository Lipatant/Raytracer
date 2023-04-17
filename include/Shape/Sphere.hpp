/*
** EPITECH PROJECT, 2023
** Shape/Sphere.hpp
** File description:
** -
*/

#pragma once
#include "Math/Point3D.hpp"
#include "Math/Vector3D.hpp"
#include "Shape/AShape.hpp"

namespace Shape {

class Sphere : public AShape
{
protected:
    Math::Point3D _center;
    Math::Vector3DValue _radius;
public:
    Sphere(void);
};

}
