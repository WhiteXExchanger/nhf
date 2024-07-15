// temps.cpp
#include "temps.h"

bool TempS::test(Brick b) const {
    return b.getTemperature() > temperature;
}

void TempS::save(ostream& ios) const {
    ios << "T" << temperature << " ";
}