/*
** EPITECH PROJECT, 2023
** Raytracer/Scene/Render/At.cpp
** File description:
** -
*/

#include <vector>
#include "Argument/Extern.hpp"
#include "Raytracer/Scene.hpp"

static Raytracer::CameraDirection getDirection(Raytracer::Camera const \
    camera, std::size_t const x, std::size_t const y)
{
    Raytracer::Camera tiltedCamera = camera;
    double ratio = (0.0 + camera.height) / camera.width;
    double verticalFov = camera.fov * ratio;

    tiltedCamera.rotation.x += ((x - camera.width * 0.5) * camera.fov) /
        camera.width;
    tiltedCamera.rotation.y -= ((y - camera.height * 0.5) * verticalFov) /
        camera.height;
    return tiltedCamera.direction();
}

static bool isMirrorAtMin(Raytracer::TextureMirrorValue const value)
{
    return (value <= Raytracer::TextureMirrorValueMinimum);
}

static bool isMirrorAtMax(Raytracer::TextureMirrorValue const value)
{
    return (value >= Raytracer::TextureMirrorValueMaximum);
}

static bool isColorAtMin(Raytracer::ColorValue const value)
{
    return (value <= Raytracer::ColorValueMinimum);
}

static bool isColorAtMax(Raytracer::ColorValue const value)
{
    return (value >= Raytracer::ColorValueMaximum);
}

static Raytracer::Color invertedAlphaColor(Raytracer::Color const &color)
{
    Raytracer::Color newColor(color);

    newColor.a = (0 - (color.a - 0.5)) + 0.5;
    return newColor.normalized();
}

static Raytracer::RayDirection reflectMirror(Raytracer::RayDirection const \
    &direction, Raytracer::RayDirection const &reflect)
{
    return direction - reflect * direction.dot(reflect) * 2;
}

static Raytracer::ColorValue randomColorValue(void)
{
    return (static_cast<Raytracer::ColorValue>(std::rand()) / RAND_MAX) * \
        Raytracer::ColorValueMaximum;
}

static Raytracer::Color getSkyBox(void)
{
    return Raytracer::Color(0.6, 0.9, 1.0, 0.2).withoutAlpha();
}

Raytracer::Color Raytracer::Scene::_renderPureLight(Raytracer::HitPointList \
    hitPointList)
{
    Raytracer::Color color(1, 1, 1);
    Raytracer::Color light(0, 0, 0);
    Raytracer::Texture texture;

    hitPointList.sort();
    while (!hitPointList.empty()) {
        texture = hitPointList.front().texture;
        if (texture.isPureLight)
            light += texture.light.withoutAlpha() * color.withoutAlpha();
        if (isColorAtMax(texture.color.a))
            return light;
        if (!isColorAtMin(texture.color.a))
            color *= invertedAlphaColor(texture.color).withoutAlpha();
        hitPointList.pop_front();
    }
    light += getSkyBox() * color;
    return light;
}

void Raytracer::Scene::_renderPureLighting(Raytracer::Ray ray, \
    Raytracer::Color const &color, Raytracer::Color &light)
{
    Raytracer::RayDirection incommingDirection(ray.direction.normalized());
    Raytracer::Color pureLightColor;
    Math::Point3DValue dotProduct;

    for (auto const &shape: shapes) {
        if (shape->isPureLight()) {
            ray.direction = shape->getCenter() - ray.origin;
            ray.direction.normalize();
            dotProduct = incommingDirection.dot(ray.direction);
            if (dotProduct < 0)
                continue;
            pureLightColor = _renderPureLight(rayListPureLights(ray)) * dotProduct;
            light = pureLightColor.withoutAlpha() * color.withoutAlpha();
        }
    }
}

Raytracer::Color Raytracer::Scene::_renderAtOnce(Raytracer::Ray ray, \
    Raytracer::HitPointList hitPointList, bool &variated)
{
    Raytracer::Color color(1, 1, 1);
    Raytracer::Color light(0, 0, 0);
    Raytracer::Texture texture;
    std::size_t rebound = Arg::INPUT.rebound;

    hitPointList.sort();
    for (std::size_t i = 0; i < rebound; i++) {
        if (hitPointList.empty()) {
            light += getSkyBox() * color;
            return light;
        }
        texture = hitPointList.front().texture;
        if (!isColorAtMin(texture.color.a) && !isColorAtMax(texture.color.a)) {
            if (randomColorValue() < texture.color.a)
                texture.color.a = Raytracer::ColorValueMaximum;
            else
                texture.color.a = Raytracer::ColorValueMinimum;
            variated = true;
        }
        if (isColorAtMin(texture.color.a)) {
            if (!isColorAtMin(texture.light.a))
                light += texture.light.withoutAlpha() * color;
            hitPointList.pop_front();
            continue;
        }
        ray.origin = hitPointList.front().position;
        hitPointList.front().reflect.normalize();
        if (isMirrorAtMax(texture.mirrorValue))
            ray.direction = reflectMirror(ray.direction, \
                hitPointList.front().reflect);
        else {
            variated = true;
            if (isMirrorAtMin(texture.mirrorValue))
                ray.direction = hitPointList.front().reflect.variation(1.0, \
                    false);
            else
                ray.direction = hitPointList.front().reflect.variation(1.0, \
                    false) * (Raytracer::TextureMirrorValueMaximum - \
                    texture.mirrorValue) + reflectMirror(ray.direction, \
                    hitPointList.front().reflect) * texture.mirrorValue;
        }
        ray.direction.normalize();
        light += texture.light.withoutAlpha() * color.withoutAlpha();
        _renderPureLighting(ray, color, light);
        color *= texture.color.withoutAlpha();
        hitPointList = rayListCollisions(ray);
        hitPointList.sort();
    }
    return light;
}

#define SCENE_RENDER_AT_FROM_LIST \
    _renderAtOnce(ray, hitPointList, needBlend).normalized()

Raytracer::DisplayPixel Raytracer::Scene::renderAt(std::size_t const x, \
    std::size_t const y)
{
    Raytracer::Color cumulatedColor;
    Raytracer::Color color;
    Raytracer::CameraDirection cameraDirection(getDirection(camera, x, y));
    Raytracer::Ray ray(cameraDirection, camera.position);
    Raytracer::HitPointList hitPointList = rayListCollisions(ray);
    std::size_t blending = Arg::INPUT.blending;
    bool needBlend = false;

    cameraDirection.normalize();
    if (blending <= 0)
        return color.toDisplayPixel();
    for (size_t i = 0; i < blending; i++) {
        if (i == 1 && !needBlend)
            return cumulatedColor.normalized().toDisplayPixel();
        cumulatedColor.addAllColorValues(SCENE_RENDER_AT_FROM_LIST);
    }
    cumulatedColor.divideEveryColor(blending);
    cumulatedColor.normalize();
    return cumulatedColor.toDisplayPixel();
}
