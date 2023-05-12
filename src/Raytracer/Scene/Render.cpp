/*
** EPITECH PROJECT, 2023
** Raytracer/Scene/Render.cpp
** File description:
** -
*/

#include <chrono>
#include <ctime>
#include <vector>
#include "Argument/Extern.hpp"
#include "Raytracer/Scene.hpp"

#define GET_TIME_NOW std::chrono::high_resolution_clock::now()
#define DISPLAY_TIME_UNIT std::micro

namespace StaticHere
{
    using DisplayDuration = double;
    using DisplayTimePoint = std::chrono::_V2::system_clock::time_point;

    class Display {
    private:
        StaticHere::DisplayDuration _duration = 0;
        StaticHere::DisplayTimePoint _start = GET_TIME_NOW;
        StaticHere::DisplayTimePoint _end;
        std::size_t _actual = 0;
        std::size_t _maximum;
    public:
        Display(std::size_t const maximum) : _maximum(maximum) { }
        //
        void display(std::ostream &stream) const;
        void resetTime(void);
    };
}

static void displayDuration(std::ostream &stream, StaticHere::DisplayDuration \
    const duration)
{
    std::size_t seconds = duration / 1000000;
    std::size_t minutes;

    if (seconds >= 60) {
        minutes = seconds / 60;
        seconds %= 60;
        if (minutes >= 60) {
            stream << minutes / 60 << "h ";
            minutes %= 60;
        }
        stream << minutes << "m ";
    }
    stream << seconds << 's';
}

void StaticHere::Display::display(std::ostream &stream) const
{
    double percent = static_cast<double>(_actual) / _maximum;

    stream << static_cast<std::size_t>(percent * 100) << "% | ";
    displayDuration(stream, _duration);
    stream << " / ";
    if (_duration > 0)
        displayDuration(stream, _duration / percent);
    else
        stream << "?s";
    stream << " | " <<_actual + 1 << " / " << _maximum;
}

std::ostream &operator<<(std::ostream &stream, StaticHere::Display const \
    &status)
{
    status.display(stream);
    return stream;
}

void StaticHere::Display::resetTime(void)
{
    _end = GET_TIME_NOW;
    _duration += std::chrono::duration<StaticHere::DisplayDuration, \
        DISPLAY_TIME_UNIT>(_end - _start).count();
    _start = _end;
    _actual++;
}

Raytracer::Display Raytracer::Scene::render(void)
{
    Raytracer::Display display(camera.width, camera.height);
    std::size_t displayWidth = display.width();
    std::size_t displayHeight = display.height();
    StaticHere::Display status(displayWidth);
    bool displayInConsole = !Arg::INPUT.noConsole;

    if (!Arg::INPUT.angularcamera) {
        Raytracer::CameraRotation cameraRotation(camera.rotation);
        cameraRotation.y *= -1;
        camera.frontBack = cameraRotation.direction().normalized();
        camera.downUp = Raytracer::CameraRotation(cameraRotation + \
            Raytracer::CameraRotation(0,90)).direction().normalized();
        camera.leftRight = camera.frontBack.cross(camera.downUp);
        camera.leftRight.normalize();
    }
    std::srand(std::time(nullptr));
    camera.rotation.normalize();
    if (shapes.size() < 1)
        return display;
    for (std::size_t x = 0; x < displayWidth; x++) {
        if (displayInConsole) {
            std::cout << status << std::endl;
            for (std::size_t y = 0; y < displayHeight; y++)
                display.at(x, y) = renderAt(x, y);
            status.resetTime();
        } else
            for (std::size_t y = 0; y < displayHeight; y++)
                display.at(x, y) = renderAt(x, y);
    }
    return display;
}
