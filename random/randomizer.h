#ifndef RANDOMIZER_H
#define RANDOMIZER_H


class Randomizer {
public:
    Randomizer() { }
    ~Randomizer() { }

    static void init();
    static int dice(int min, int max);

private:
    Randomizer(const Randomizer&);
    Randomizer& operator=(const Randomizer&);
};


#endif // RANDOMIZER_H
