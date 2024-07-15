// contacts.h
#pragma once
#include "component.h"

/**
 * @class ContactS
 * @brief Represents a contact sensor component.
 */
class ContactS : public Component {
public:
    ContactS(bool status) : status(status) {}
    
    bool test(Brick) const override;
    void save(ostream&) const override;

    ~ContactS() {}
private:
    bool status; ///< Status of the contact sensor.
};