#include "params.h"
#include <iostream>


Params::Params() :
    IParams()
{
    for (const auto& param : EMainParam) {
        _main_params[param] = 0.0;
    }
    for (const auto& param : ELifeParam) {
        _life_params[param] = 0.0;
    }
    for (const auto& param : EMoveParam) {
        _move_params[param] = 0.0;
    }
    for (const auto& param : EExpParam) {
        _exp_params[param] = 0.0;
    }
    for (const auto& param : EHitParam) {
        _hit_params[param] = 0.0;
    }
    for (const auto& param : EPosParam) {
        _pos_params[param] = 0.0;
    }
}

Params::Params(const Params& other) :
    IParams( other ),
    _main_params( other._main_params ),
    _life_params( other._life_params ),
    _move_params( other._move_params ),
    _exp_params( other._exp_params ),
    _hit_params( other._hit_params ),
    _pos_params( other._pos_params )
{
}

Params::Params(const IParams& other) :
    Params( static_cast< const Params& >(other) )
{
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
    _main_params[param] = value;
}

void Params::set_life_param(ELifeParams param, float value) {
    _life_params[param] = value;
}

void Params::set_move_param(EMoveParams param, float value) {
    _move_params[param] = value;
}

void Params::set_exp_param(EExpParams param, float value) {
    _exp_params[param] = value;
}

void Params::set_hit_param(EHitParams param, float value) {
    _hit_params[param] = value;
}

void Params::set_pos_param(EPosParams param, float value) {
    _pos_params[param] = value;
}


void Params::print(bool requirements) const {
    if (requirements) {
        std::cout << "requirements:\n";
        std::cout << "\tlevel     : " << static_cast<int>(_exp_params.at(EExpParams::_level)) << '\n';
        std::cout << "\tstrength  : " << static_cast<int>(_main_params.at(EMainParams::_strength)) << '\n';
        std::cout << "\tstamina   : " << static_cast<int>(_main_params.at(EMainParams::_stamina)) << '\n';
        std::cout << "\tagility   : " << static_cast<int>(_main_params.at(EMainParams::_agility)) << '\n';
        std::cout << "\tmind      : " << static_cast<int>(_main_params.at(EMainParams::_mind)) << '\n';
        std::cout << "\twill      : " << static_cast<int>(_main_params.at(EMainParams::_will)) << '\n';
        std::cout << "\tluck      : " << static_cast<int>(_main_params.at(EMainParams::_luck)) << "\n\n";
    }
    else {
        std::cout << "params:\n";
        std::cout << "\tdamage    : " << static_cast<int>(_hit_params.at(EHitParams::_min_damage));
        std::cout << '-' << static_cast<int>(_hit_params.at(EHitParams::_max_damage)) << "\n\n";
    }
}


IParams& Params::operator=(const IParams& other) {
    return operator=( static_cast< const Params& >(other) );
}

Params& Params::operator=(const Params& other) {
    for (const auto& param : EMainParam) {
        _main_params[param] = other._main_params.at(param);
    }
    for (const auto& param : ELifeParam) {
        _life_params[param] = other._life_params.at(param);
    }
    for (const auto& param : EMoveParam) {
        _move_params[param] = other._move_params.at(param);
    }
    for (const auto& param : EExpParam) {
        _exp_params[param] = other._exp_params.at(param);
    }
    for (const auto& param : EHitParam) {
        _hit_params[param] = other._hit_params.at(param);
    }
    for (const auto& param : EPosParam) {
        _pos_params[param] = other._pos_params.at(param);
    }
    return *this;
}

Params& Params::operator+=(const Params& other) {
    for (const auto& param : EMainParam) {
        _main_params[param] += other._main_params.at(param);
    }
    for (const auto& param : ELifeParam) {
        _life_params[param] += other._life_params.at(param);
    }
    for (const auto& param : EMoveParam) {
        _move_params[param] += other._move_params.at(param);
    }
    for (const auto& param : EExpParam) {
        _exp_params[param] += other._exp_params.at(param);
    }
    for (const auto& param : EHitParam) {
        _hit_params[param] += other._hit_params.at(param);
    }
    for (const auto& param : EPosParam) {
        _pos_params[param] += other._pos_params.at(param);
    }
    return *this;
}


