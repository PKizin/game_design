#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <string>


class Randomizer {
public:
    Randomizer() { }
    ~Randomizer() { }

    static void init();

    static int dice_int(int min, int max);
    static float dice_real(int min, int max);
    static std::string timestamp();

private:
    Randomizer(const Randomizer&);
    Randomizer& operator=(const Randomizer&);
};


#endif // RANDOMIZER_HPP
