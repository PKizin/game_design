#include "randomizer.hpp"
#include <cstdlib>
#include <ctime>
#include <chrono>


void Randomizer::init() {
    srand(time(0) * time(0));
}


int Randomizer::dice_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

float Randomizer::dice_real(int min, int max) {
    return static_cast<float>( Randomizer::dice_int(min, max) );
}

std::string Randomizer::timestamp() {
    const auto& today = std::chrono::system_clock::now();
    const auto& tt = std::chrono::system_clock::to_time_t( today );
    return ctime(&tt);
}

