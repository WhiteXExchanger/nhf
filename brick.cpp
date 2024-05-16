// brick.cpp

#include "brick.h"
#include <random>

using namespace std;

double Brick::getRandomDouble() { //Segédfüggvény random értékek generálásához FORRÁS: https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c
    double lower_bound = 5;
    double upper_bound = 120;
    double f = (double)rand() / RAND_MAX;
    return lower_bound + f * (upper_bound - lower_bound);
}
