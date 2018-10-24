#ifndef I_PARAMS_HPP
#define I_PARAMS_HPP

#include "i_main_params.hpp"
#include "i_life_params.hpp"
#include "i_move_params.hpp"
#include "i_exp_params.hpp"
#include "i_hit_params.hpp"
#include "i_pos_params.hpp"

#include <iostream>
#include <typeinfo>


class IParams : public IMainParams, public ILifeParams, public IMoveParams, public IExpParams, public IHitParams, public IPosParams {
public:
    virtual float get_main_param(EMainParams) const = 0;
    virtual float get_life_param(ELifeParams) const = 0;
    virtual float get_move_param(EMoveParams) const = 0;
    virtual float get_exp_param(EExpParams) const = 0;
    virtual float get_hit_param(EHitParams) const = 0;
    virtual float get_pos_param(EPosParams) const = 0;

    virtual void set_main_param(EMainParams, float) = 0;
    virtual void set_life_param(ELifeParams, float) = 0;
    virtual void set_move_param(EMoveParams, float) = 0;
    virtual void set_exp_param(EExpParams, float) = 0;
    virtual void set_hit_param(EHitParams, float) = 0;
    virtual void set_pos_param(EPosParams, float) = 0;

    virtual IParams& operator=(const IParams&) { return *this; }

protected:
    IParams() { }
    IParams(const IParams&) { }
    virtual ~IParams() { }
};


#endif // I_PARAMS_HPP
