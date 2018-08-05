#ifndef I_EXP_PARAMS_H
#define I_EXP_PARAMS_H

#include "e_params_categories.h"


class IExpParams {
public:
    virtual float get_exp_param(EExpParams) const = 0;
    virtual void set_exp_param(EExpParams, float) = 0;

protected:
    IExpParams() { }
    virtual ~IExpParams() { }

private:
    IExpParams(const IExpParams&);
    IExpParams& operator=(const IExpParams&);
};


#endif // I_EXP_PARAMS_H
