// component.cpp
#include "component.h"
#include "brick.h"
#include <iostream>

bool Component::test(Brick b) const {
    for (auto c : comps) {
        if (c->test(b)) return true;
    }
    return false;
}

void Component::save(ostream& os) const {
    return;
}

const std::vector<Component*>& Component::getComps() const {
    return comps;
}

std::vector<size_t> Component::indexesInCollection(const vector<Component*>& collection) const {
    std::vector<size_t> indexes;
    
    size_t index = 0;
    for (auto child : comps) {
        index = 0;
        for (auto iter : collection) {
            if (child == iter) {
                indexes.push_back(index);
            }
            ++index;
        }
    }

    return indexes;
}

void Component::add(Component* c) {
    comps.push_back(c);
}
