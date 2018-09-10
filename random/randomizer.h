#ifndef RANDOMIZER_H
#define RANDOMIZER_H


class Randomizer {
public:
    Randomizer() { }
    ~Randomizer() { }

    static void init();
    static int dice_int(int min, int max);
    static float dice_real(int min, int max);

private:
    Randomizer(const Randomizer&);
    Randomizer& operator=(const Randomizer&);
};


#endif // RANDOMIZER_H
