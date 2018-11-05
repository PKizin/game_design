#ifndef I_MOVE_STRATEGY_HPP
#define I_MOVE_STRATEGY_HPP

#include "e_params_categories.hpp"


class IMoveStrategy {
public:
    virtual void move(ICreature&, EDirection) = 0;

protected:
    IMoveStrategy();
    virtual ~IMoveStrategy();
};


#endif // I_MOVE_STRATEGY_HPP
