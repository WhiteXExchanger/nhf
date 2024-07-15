// temps.h
#pragma once
#include "component.h"

/**
 * @class TempS
 * @brief Represents a temperature sensor component.
 */
class TempS : public Component {
public:
    TempS(double temperature) : temperature(temperature) {}
    
    bool test(Brick) const override;
    void save(ostream&) const;

    ~TempS() {}
private:
    double temperature; ///< Temperature to be detected by the sensor.
};