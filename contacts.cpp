// contacts.cpp
#include "contacts.h"

bool ContactS::test(Brick b) const {
    return status;
}

void ContactS::save(ostream& ios) const {
    ios << "c";
    if (status) ios << "1 ";
    else ios << "0 ";
}