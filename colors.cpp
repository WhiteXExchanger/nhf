//colors.cpp
#include "colors.h"

bool ColorS::test(Brick b) const {
    return b.getColor() == color;
}

void ColorS::save(ostream& ios) const {
    ios << "C" << color << " ";
}