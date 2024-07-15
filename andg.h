// andg.h
#pragma once
#include "component.h"

/**
 * @class AndG
 * @brief Represents an AND gate component.
 */
class AndG : public Component {
public:
    bool test(Brick) const override;
    void save(ostream&) const override;
    
    ~AndG() {}
};