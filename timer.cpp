// timer.cpp
#include "timer.h"
#include <time.h>

bool Timer::test(Brick b) const {
    time_t t = seconds + time(NULL);
    while(t > time(NULL)) {
        continue;
    }
    return true;
}

void Timer::save(ostream& ios) const {
    ios << "T" << seconds << " ";
}