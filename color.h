// color.h
#pragma once
#include <iostream>

using namespace std;

/**
 * @enum Color
 * @brief Enumeration for colors.
 */
enum Color {
    RED,
    GREEN,
    BLUE,
    MAGENTA,
    YELLOW,
    CYAN
};

/**
 * @brief Overloaded output stream operator for the Color enum.
 * @param os The output stream.
 * @param color The color to output.
 * @return The output stream.
 */
ostream& operator<<(std::ostream& os, const Color& color);

/**
 * @brief Overloaded input stream operator for the Color enum.
 * @param is The input stream.
 * @param color The color to input.
 * @return The input stream.
 */
istream& operator>>(istream& is, Color& color);