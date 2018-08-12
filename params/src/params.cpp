#include "params.h"


Params::Params() :
    IParams()
{
    for (const auto& param : EMainParam) {
        _main_params.at(param) = 0.0;
    }
    for (const auto& param : ELifeParam) {
        _life_params.at(param) = 0.0;
    }
    for (const auto& param : EMoveParam) {
        _move_params.at(param) = 0.0;
    }
    for (const auto& param : EExpParam) {
        _exp_params.at(param) = 0.0;
    }
    for (const auto& param : EHitParam) {
        _hit_params.at(param) = 0.0;
    }
    for (const auto& param : EPosParam) {
        _pos_params.at(param) = 0.0;
    }
}

Params::Params(const Params& other) :
    IParams(other)
{
    for (const auto& param : EMainParam) {
        _main_params.at(param) = other._main_params.at(param);
    }
    for (const auto& param : ELifeParam) {
        _life_params.at(param) = other._life_params.at(param);
    }
    for (const auto& param : EMoveParam) {
        _move_params.at(param) = other._move_params.at(param);
    }
    for (const auto& param : EExpParam) {
        _exp_params.at(param) = other._exp_params.at(param);
    }
    for (const auto& param : EHitParam) {
        _hit_params.at(param) = other._hit_params.at(param);
    }
    for (const auto& param : EPosParam) {
        _pos_params.at(param) = other._pos_params.at(param);
    }
}


float Params::get_main_param(EMainParams param) const {
    return _main_params.at(param);
}

float Params::get_life_param(ELifeParams param) const {
    return _life_params.at(param);
}

float Params::get_move_param(EMoveParams param) const {
    return _move_params.at(param);
}

float Params::get_exp_param(EExpParams param) const {
    return _exp_params.at(param);
}

float Params::get_hit_param(EHitParams param) const {
    return _hit_params.at(param);
}

float Params::get_pos_param(EPosParams param) const {
    return _pos_params.at(param);
}


void Params::set_main_param(EMainParams param, float value) {
    _main_params.at(param) = value;
}

void Params::set_life_param(ELifeParams param, float value) {
    _life_params.at(param) = value;
}

void Params::set_move_param(EMoveParams param, float value) {
    _move_params.at(param) = value;
}

void Params::set_exp_param(EExpParams param, float value) {
    _exp_params.at(param) = value;
}

void Params::set_hit_param(EHitParams param, float value) {
    _hit_params.at(param) = value;
}

void Params::set_pos_param(EPosParams param, float value) {
    _pos_params.at(param) = value;
}


Params& Params::operator=(const Params& other) {
    for (const auto& param : EMainParam) {
        _main_params.at(param) = other._main_params.at(param);
    }
    for (const auto& param : ELifeParam) {
        _life_params.at(param) = other._life_params.at(param);
    }
    for (const auto& param : EMoveParam) {
        _move_params.at(param) = other._move_params.at(param);
    }
    for (const auto& param : EExpParam) {
        _exp_params.at(param) = other._exp_params.at(param);
    }
    for (const auto& param : EHitParam) {
        _hit_params.at(param) = other._hit_params.at(param);
    }
    for (const auto& param : EPosParam) {
        _pos_params.at(param) = other._pos_params.at(param);
    }
    return *this;
}

Params& Params::operator+=(const Params& other) {
    for (const auto& param : EMainParam) {
        _main_params.at(param) += other._main_params.at(param);
    }
    for (const auto& param : ELifeParam) {
        _life_params.at(param) += other._life_params.at(param);
    }
    for (const auto& param : EMoveParam) {
        _move_params.at(param) += other._move_params.at(param);
    }
    for (const auto& param : EExpParam) {
        _exp_params.at(param) += other._exp_params.at(param);
    }
    for (const auto& param : EHitParam) {
        _hit_params.at(param) += other._hit_params.at(param);
    }
    for (const auto& param : EPosParam) {
        _pos_params.at(param) += other._pos_params.at(param);
    }
    return *this;
}


