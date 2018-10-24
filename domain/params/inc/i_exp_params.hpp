#ifndef I_EXP_PARAMS_HPP
#define I_EXP_PARAMS_HPP

#include "e_params_categories.hpp"


class IExpParams {
public:
    virtual float get_exp_param(EExpParams) const = 0;
    virtual void set_exp_param(EExpParams, float) = 0;

protected:
    IExpParams() { }
    virtual ~IExpParams() { }
};


#endif // I_EXP_PARAMS_HPP
