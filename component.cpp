// component.cpp

#include "component.h"
#include "brick.cpp"
#include <stdlib.h>
#include <iostream>

static std::queue<Component*> que = queue<Component*>();

Component::~Component() {
    for(auto c : comps) {
        c->~Component();
    }
}

bool Component::test(Brick b) {
    return false;
}

void Component::setID(size_t idToSet) {
    this->id = idToSet++;
    
    for (auto c : comps) {
        que.push(c);
    }

    if (que.empty()) return;
    else {
        Component* c = que.front();
        que.pop();
        c->setID(idToSet);
    }
}

bool Component::insert(EComponent ec, size_t idToFind) {
    if(idToFind==id) {
        add(ec);
        return true;
    }

    for (auto c : comps) {
        que.push(c);
    }

    bool isSuccess;
    if (que.empty()) return false;
    else {
        Component* c = que.front();
        que.pop();
        isSuccess = c->insert(ec, idToFind);
    }
    return isSuccess;
}

bool Component::remove(size_t idToFind) {
    if(idToFind==id) {
        delete this;
        return true;
    }

    for (auto c : comps) {
        que.push(c);
    }

    bool isSuccess;
    if (que.empty()) return false;
    else {
        Component* c = que.front();
        que.pop();
        isSuccess = c->remove(idToFind);
    }
    return isSuccess;
}

ostream& Component::write(ostream& os) {
    os << endl << id << ": ";
    for (auto c : comps) {
        os << c->id << ", ";
    }

    for (auto c : comps) {
        que.push(c);
    }

    if (que.empty()) return os;
    else {
        Component* c = que.front();
        que.pop();
        c->write(os);
    }
    return os;
}

void Component::add(EComponent ec) {
    comps.push_back(new Component());
}