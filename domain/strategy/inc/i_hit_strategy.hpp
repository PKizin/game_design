#ifndef I_HIT_STRATEGY_HPP
#define I_HIT_STRATEGY_HPP


class IHitStrategy {
public:
    virtual void hit(ICreature&) = 0;

protected:
    IHitStrategy();
    virtual ~IHitStrategy();
};


#endif // I_HIT_STRATEGY_HPP
