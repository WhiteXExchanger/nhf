// component.h
#pragma once

#include <queue>
#include <vector>
#include <iostream>
#include "brick.h"
#include "ecomponent.h"

using namespace std;

class Component {
public:
    Component() : id(1) {}
    Component(size_t id) : id(id) {}
    virtual bool test(Brick);                   // Leteszteli az adott téglával az ebbe belekötött komponensek állapotát, végül beállítja ennek az állapotát
    void add(EComponent, size_t);              // A fában lefele átad egy komponenst hogy hozzáadja az adott i-edik komponensnek
    bool insert(EComponent, size_t, size_t);
    bool remove(size_t, Component*);
    void cleanup(Component*);
    ostream& write(ostream&);
    void setID(size_t id = 1);
    size_t max() const;
    virtual ~Component();
private:
    size_t id;
    vector<Component*> comps;              // Komponensek amik beállítják ennek a komponensnek az állapotát
    bool status;                                // Komponens állapota
};