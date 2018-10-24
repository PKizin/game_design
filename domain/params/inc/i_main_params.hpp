#ifndef I_MAIN_PARAMS_HPP
#define I_MAIN_PARAMS_HPP

#include "e_params_categories.hpp"


class IMainParams {
public:
    virtual float get_main_param(EMainParams) const = 0;
    virtual void set_main_param(EMainParams, float) = 0;

protected:
    IMainParams() { }
    virtual ~IMainParams() { }
};


#endif // I_MAIN_PARAMS_HPP
