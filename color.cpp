#include "color.h"

ostream& operator<<(std::ostream& os, const Color& color) {
    unsigned u = color;
    os << u;
    return os;
}

istream& operator>>(istream& is, Color& color) {
    unsigned u = 0;
    is >> u;
    color = static_cast<Color>(u);
    return is;
}