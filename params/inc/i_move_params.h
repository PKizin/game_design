#ifndef I_MOVE_PARAMS_H
#define I_MOVE_PARAMS_H

#include "e_params_categories.h"


class IMoveParams {
public:
    virtual float get_move_param(EMoveParams) const = 0;
    virtual void set_move_param(EMoveParams, float) = 0;

protected:
    IMoveParams() { }
    virtual ~IMoveParams() { }

private:
    IMoveParams(const IMoveParams&);
    IMoveParams& operator=(const IMoveParams&);
};


#endif // I_MOVE_PARAMS_H