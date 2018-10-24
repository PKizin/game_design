#ifndef I_POS_PARAMS_HPP
#define I_POS_PARAMS_HPP

#include "e_params_categories.hpp"


class IPosParams {
public:
    virtual float get_pos_param(EPosParams) const = 0;
    virtual void set_pos_param(EPosParams, float) = 0;

protected:
    IPosParams() { }
    virtual ~IPosParams() { }
};


#endif // I_POS_PARAMS_HPP
