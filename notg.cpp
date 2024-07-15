// notg.cpp
#include "notg.h"

bool NotG::test(Brick b) const {
    return !Component::test(b);
}

void NotG::save(ostream& ios) const {
    ios << "n ";
}