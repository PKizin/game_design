#ifndef PARAMS_H
#define PARAMS_H

#include "i_params.h"
#include "map"


class Params : public IParams {
public:
    Params();
    virtual ~Params() { }

    float get_main_param(EMainParams) const override;
    float get_life_param(ELifeParams) const override;
    float get_move_param(EMoveParams) const override;
    float get_exp_param(EExpParams) const override;
    float get_hit_param(EHitParams) const override;
    float get_pos_param(EPosParams) const override;

    void set_main_param(EMainParams, float) override;
    void set_life_param(ELifeParams, float) override;
    void set_move_param(EMoveParams, float) override;
    void set_exp_param(EExpParams, float) override;
    void set_hit_param(EHitParams, float) override;
    void set_pos_param(EPosParams, float) override;

    virtual IParams& operator=(const IParams&) override;
    Params& operator=(const Params&);
    Params& operator+=(const Params&);

private:
    std::map< EMainParams, float > _main_params;
    std::map< ELifeParams, float > _life_params;
    std::map< EMoveParams, float > _move_params;
    std::map< EExpParams, float > _exp_params;
    std::map< EHitParams, float > _hit_params;
    std::map< EPosParams, float > _pos_params;
};


#endif // PARAMS_H
