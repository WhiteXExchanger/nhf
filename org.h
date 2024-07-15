// org.h
#pragma once
#include "component.h"

/**
 * @class OrG
 * @brief Represents an OR gate component.
 */
class OrG : public Component {
public:
    bool test(Brick) const override;
    void save(ostream&) const;

    ~OrG() {}
};