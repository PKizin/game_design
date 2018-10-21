#ifndef I_HIT_PARAMS_H
#define I_HIT_PARAMS_H

#include "e_params_categories.hpp"


class IHitParams {
public:
    virtual float get_hit_param(EHitParams) const = 0;
    virtual void set_hit_param(EHitParams, float) = 0;

protected:
    IHitParams() { }
    virtual ~IHitParams() { }
};


#endif // I_HIT_PARAMS_H
