// model.h
#pragma once

#include <stdlib.h>
#include "component.h"
#include "ecomponent.h"

class Model {
public:
    // Egy mélység és felfedezési sorrend (BFS) meghatározott sorrendiség 
    // szerint lehet megjelölni melyik előző elemhez csaklakozzon.
    // PL: ha A - B, A - C a fa struktúrája:
    //      A-1               - Legfelső sorba rajzolja ki mert mélysége 0 ID-je: 1 mert ő volt az első megtalált elem ("Legfelül" minig a riasztó van) 
    //  B-2     C-3           - Második sor mert mélységük 1, ID-jük: 2 és 3 azaz ők voltak a következő elemek

    Model(ostream& os) : os(os) {}
    bool add(EComponent, size_t);       // Hozzáad egy új komponenst a fához
    bool remove(size_t);                // Eltávolít egy komponenst a fából
    bool modify(EComponent ec, size_t i);                // Lecserél egy komponenst (ha új értéket szeretnénk beállítani egy komponensnek is ezt kell használni)
    bool testModel(Brick);                  // Leteszteli a modellt a beadott téglával
    void simulate(size_t n);                // Létrehoz egy téglákkal teli tömböt véletlenszerű adatokkal és leteszteli azokkal a modellt 
    void drawSimulation();                  // Megrajzolja mi történik a futószallagonű
    void drawComponentTree();

private:
    ostream& os;
    Component alarm;
};