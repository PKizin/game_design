#include "randomizer.h"
#include <cstdlib>
#include <ctime>


void Randomizer::init() {
    srand(time(0) * time(0));
}


int Randomizer::dice_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

float Randomizer::dice_real(int min, int max) {
    return static_cast<float>( Randomizer::dice_int(min, max) );
}

