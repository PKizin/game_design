#ifndef I_CREATURE_FACTORY_HPP
#define I_CREATURE_FACTORY_HPP


class ICreatureFactory {
public:
    virtual void build_creature(/* ICreature& */) const = 0;

protected:
    ICreatureFactory() { }
    virtual ~ICreatureFactory() { }
};


#endif // I_CREATURE_FACTORY_HPP
