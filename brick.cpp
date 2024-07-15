// brick.cpp
#include "brick.h"
#include <random>

using namespace std;

Brick::Brick() {
    temperature = getRandomDouble();
    color = static_cast<Color>(rand()%CYAN); // FORRÁS: https://stackoverflow.com/questions/2999012/generating-random-enums
}

double Brick::getRandomDouble() { //Segédfüggvény random értékek generálásához FORRÁS: https://stackoverflow.com/questions/2704521/generate-random-double-numbers-in-c
    double lower_bound = 5;
    double upper_bound = 120;
    double f = (double)rand() / RAND_MAX;
    return lower_bound + f * (upper_bound - lower_bound);
}

ostream& operator<<(ostream& os, Brick& b) {
    os << "Brick data: \n\tTemperature: " << b.temperature << "C\n\tColor: ";
    switch (b.color)
    {
    case RED:
        os << "red" << endl;
        break;
    case GREEN:
        os << "green" << endl;
        break;
    case BLUE:
        os << "blue" << endl;
        break;
    case YELLOW:
        os << "yellow" << endl;
        break;
    case MAGENTA:
        os << "magenta" << endl;
        break;
    case CYAN:
        os << "cyan" << endl;
        break;
    default:
        break;
    }
    return os;
}
