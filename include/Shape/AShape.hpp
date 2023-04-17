/*
** EPITECH PROJECT, 2023
** Shape/AShape.hpp
** File description:
** -
*/

#pragma once
#include "Shape/IShape.hpp"

namespace Shape {

class AShape : public IShape
{
protected:
    std::string _name = "UnknownShape";
public:
    AShape(void);
    AShape(std::string const &name);
    //
    std::string name(void) const;
};

}
