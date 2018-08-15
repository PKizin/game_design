#ifndef I_CREATURE_FACTORY_H
#define I_CREATURE_FACTORY_H


class ICreatureFactory {
public:
    virtual void build_creature(/* ICreature& */) = 0;

protected:
    ICreatureFactory() { }
    virtual ~ICreatureFactory() { }
};


#endif // I_CREATURE_FACTORY_H
