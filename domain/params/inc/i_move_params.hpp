#ifndef I_MOVE_PARAMS_HPP
#define I_MOVE_PARAMS_HPP

#include "e_params_categories.hpp"


class IMoveParams {
public:
    virtual float get_move_param(EMoveParams) const = 0;
    virtual void set_move_param(EMoveParams, float) = 0;

protected:
    IMoveParams() { }
    virtual ~IMoveParams() { }
};


#endif // I_MOVE_PARAMS_HPP
