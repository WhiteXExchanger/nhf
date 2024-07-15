// telga.h
#pragma once
#include "color.h"

/**
 * @class Brick
 * @brief Represents a brick with temperature and color properties.
 */
class Brick {
public:
    /**
     * @brief Constructs a brick with random values.
     */
    Brick();

    /**
     * @brief Constructs a brick given values.
     */
    Brick(double temperature, Color color) : temperature(temperature), color(color) {};

    /**
     * @brief Returns the temperature of the brick.
     * @return double
     */
    double getTemperature() { return temperature; }

    /**
     * @brief Returns the color of the brick.
     * @return Color
     */
    Color getColor() { return color; }
    
    friend ostream& operator<<(ostream& os, Brick& b);
private:
    /**
     * @brief Gets a random double value.
     * @return A random double.
     */
    double getRandomDouble();

    double temperature; ///< Temperature of the brick.
    Color color; ///< Color of the brick.
};