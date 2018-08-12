#ifndef I_POS_PARAMS_H
#define I_POS_PARAMS_H

#include "e_params_categories.h"


class IPosParams {
public:
    virtual float get_pos_param(EPosParams) const = 0;
    virtual void set_pos_param(EPosParams, float) = 0;

protected:
    IPosParams() { }
    virtual ~IPosParams() { }
};


#endif // I_POS_PARAMS_H
