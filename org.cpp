// org.cpp
#include "org.h"

bool OrG::test(Brick b) const {
    return Component::test(b);
}

void OrG::save(ostream& ios) const {
    ios << "o ";
}