#include "randomizer.h"
#include <cstdlib>
#include <ctime>


void Randomizer::init() {
    srand(time(0) * time(0));
}


int Randomizer::dice(int min, int max) {
    return min + rand() % (max - min + 1);
}

