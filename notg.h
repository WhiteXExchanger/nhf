// notg.h
#pragma once
#include "component.h"

/**
 * @class NotG
 * @brief Represents a NOT gate component.
 */
class NotG : public Component {
public:
    bool test(Brick) const override;
    void save(ostream&) const;

    ~NotG() {}
};