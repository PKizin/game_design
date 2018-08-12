#ifndef I_PARAMS_H
#define I_PARAMS_H

#include "i_main_params.h"
#include "i_life_params.h"
#include "i_move_params.h"
#include "i_exp_params.h"
#include "i_hit_params.h"
#include "i_pos_params.h"


class IParams : public IMainParams, public ILifeParams, public IMoveParams, public IExpParams, public IHitParams, public IPosParams {
public:
    IParams() : IMainParams(), ILifeParams(), IMoveParams(), IExpParams(), IHitParams(), IPosParams() { }
    virtual ~IParams() { }

    float get_main_param(EMainParams) const override { return 0.0; }
    float get_life_param(ELifeParams) const override { return 0.0; }
    float get_move_param(EMoveParams) const override { return 0.0; }
    float get_exp_param(EExpParams) const override { return 0.0; }
    float get_hit_param(EHitParams) const override { return 0.0; }
    float get_pos_param(EPosParams) const override { return 0.0; }

    void set_main_param(EMainParams, float) override { }
    void set_life_param(ELifeParams, float) override { }
    void set_move_param(EMoveParams, float) override { }
    void set_exp_param(EExpParams, float) override { }
    void set_hit_param(EHitParams, float) override { }
    void set_pos_param(EPosParams, float) override { }

    virtual IParams& operator=(const IParams&) { return *this; }
};


#endif // I_PARAMS_H
