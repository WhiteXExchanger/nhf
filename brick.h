// telga.h
#pragma once

#include "color.h"

class Brick {
public:
    Brick() {
        temperature = getRandomDouble();
        color = static_cast<Color>(rand()%CYAN); // FORRÁS: https://stackoverflow.com/questions/2999012/generating-random-enums
    }
    Brick(double temperature, Color color) : temperature(temperature), color(color) {};
    double getTemperature() { return temperature; }
    Color getColor() { return color; }
private:
    double temperature;
    Color color;
    double getRandomDouble();
};