// andg.cpp
#include "andg.h"

bool AndG::test(Brick b) const {
    for (auto c : getComps()) {
        if (!c->test(b)) {
            return false;
        }
    }
    return true;
}

void AndG::save(ostream& ios) const {
    ios << "a ";
}