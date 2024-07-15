// timer.h
#pragma once
#include "component.h"
#include "brick.h"

/**
 * @class Timer
 * @brief Represents a timer component.
 */
class Timer : public Component {
public:
    Timer(time_t seconds) : seconds(seconds) {}
    
    bool test(Brick) const override;
    void save(ostream&) const;

    ~Timer() {}
private:
    time_t seconds; ///< Duration of the timer.
};