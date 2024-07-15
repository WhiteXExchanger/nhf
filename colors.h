// colors.h
#pragma once
#include "component.h" 
#include "color.h"

/**
 * @class ColorS
 * @brief Represents a color sensor component.
 */
class ColorS : public Component {
public:
    ColorS(Color color) : color(color) {}
    
    bool test(Brick) const override;
    void save(ostream&) const;

    ~ColorS() {}
private:
    Color color; ///< Color to be detected by the sensor.
};