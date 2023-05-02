/*
** EPITECH PROJECT, 2023
** Raytracer/Scene/Render/At.cpp
** File description:
** -
*/

#include <vector>
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

Raytracer::Color Raytracer::Scene::_renderAtOnce(Raytracer::Ray ray, \
    Raytracer::HitPointList hitPointList, bool &variated)
{
    Raytracer::Color color(1, 1, 1);
    Raytracer::Color light(0, 0, 0);
    Raytracer::Texture texture;

    hitPointList.sort();
    for (std::size_t i = 0; i < 10; i++) {
        if (hitPointList.size() < 1) {
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
        light += texture.light.withoutAlpha() * color.withoutAlpha();
        color *= texture.color.withoutAlpha();
        ray.origin = hitPointList.front().position;
        if (isMirrorAtMax(texture.mirrorValue))
            ray.direction = reflectMirror(ray.direction, \
                hitPointList.front().reflect);
        else {
            variated = true;
            if (isMirrorAtMin(texture.mirrorValue))
                ray.direction = hitPointList.front().reflect.variation(1.0);
            else
                ray.direction = hitPointList.front().reflect.variation(1.0) * \
                    (Raytracer::TextureMirrorValueMaximum - \
                    texture.mirrorValue) + reflectMirror(ray.direction, \
                    hitPointList.front().reflect) * texture.mirrorValue;
        }
        ray.direction.normalize();
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
    std::size_t blending = 1;
    bool needBlend = false;

    cameraDirection.normalize();
    if (blending <= 0)
        return color.toDisplayPixel();
    for (size_t i = 0; i < blending; i++) {
        if (i == 1 && !needBlend)
            return cumulatedColor.toDisplayPixel();
        cumulatedColor.addAllColorValues(SCENE_RENDER_AT_FROM_LIST);
    }
    cumulatedColor.divideEveryColor(blending);
    return cumulatedColor.toDisplayPixel();
}
