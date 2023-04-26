/*
** EPITECH PROJECT, 2023
** Raytracer/Scene/Render/FromList.cpp
** File description:
** -
*/

#include <vector>
#include "Raytracer/Scene.hpp"

static void emitLight(Raytracer::Color &color, Raytracer::Color &light, \
    Raytracer::Texture const &texture)
{
    light += texture.light;
    color = texture.light + color * (1 - texture.light.a);
}

Raytracer::Color Raytracer::Scene::renderFromList(Raytracer::HitPointList \
    hitPointList, Raytracer::Color light, std::size_t const recurrence, \
    bool &variated)
{
    Raytracer::Texture texture;
    Raytracer::Color color;

    if (recurrence <= 0 || hitPointList.size() < 1)
        return light.withoutAlpha();
    hitPointList.sort();
    texture = hitPointList.front().texture;
    color = texture.color;
    if (texture.light.a >= Raytracer::ColorValueMaximum)
        return texture.light.withoutAlpha();
    if (texture.light.a > Raytracer::ColorValueMinimum)
        emitLight(color, light, texture);
    if (color.a <= Raytracer::ColorValueMinimum)
        return color;
    Raytracer::Ray reflect(hitPointList.front().position, \
        Raytracer::RayDirection());
    if (texture.mirrorValue < Raytracer::TextureMirrorValueMaximum) {
        variated = true;
        reflect.direction = hitPointList.front().reflect.variation(1.0);
        color *= renderFromList(rayListCollisions(reflect), light, \
            recurrence - 1, variated);
    }
    if (color.a < Raytracer::ColorValueMaximum) {
        hitPointList.pop_front();
        color += renderFromList(hitPointList, light, recurrence, variated) * \
            (1 - color.a);
    }
    return color;
}
