#ifndef I_LIFE_PARAMS_HPP
#define I_LIFE_PARAMS_HPP

#include "e_params_categories.hpp"


class ILifeParams {
public:
    virtual float get_life_param(ELifeParams) const = 0;
    virtual void set_life_param(ELifeParams, float) = 0;

protected:
    ILifeParams() { }
    virtual ~ILifeParams() { }
};


#endif // I_LIFE_PARAMS_HPP
