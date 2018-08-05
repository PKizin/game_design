#ifndef I_LIFE_PARAMS_H
#define I_LIFE_PARAMS_H

#include "e_params_categories.h"


class ILifeParams {
public:
    virtual float get_life_param(ELifeParams) const = 0;
    virtual void set_life_param(ELifeParams, float) = 0;

protected:
    ILifeParams() { }
    virtual ~ILifeParams() { }

private:
    ILifeParams(const ILifeParams&);
    ILifeParams& operator=(const ILifeParams&);
};


#endif // I_LIFE_PARAMS_H
