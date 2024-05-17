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

size_t Component::max() const {
    if (comps.empty()) return id;

    for (auto c : comps) {
        que.push(c);
    }

    if (que.empty()) return id;
    else {
        Component* c = que.front();
        que.pop();
        size_t cmax = c->max();
        if (cmax > id) { return cmax; }
        else { return id; }
    }
}

bool Component::insert(EComponent ec, size_t idToFind, size_t newID) {
    if(idToFind==id) {
        add(ec, newID);
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
        isSuccess = c->insert(ec, idToFind, newID);
    }
    return isSuccess;
}

void Component::cleanup(Component* comp) {
    size_t i = 0;
    for(auto c : comps) {
        if(c == comp) {
            comps.erase(comps.begin()+i);
        }
        ++i;
    }
}

bool Component::remove(size_t idToFind, Component* prevComp) {
    if(idToFind==id) {
        prevComp->cleanup(this);
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
        isSuccess = c->remove(idToFind, this);
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

void Component::add(EComponent ec, size_t id) {
    comps.push_back(new Component(id));
}