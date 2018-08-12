#ifndef E_PARAMS_CATEGORIES_H
#define E_PARAMS_CATEGORIES_H


enum class EMainParams {
    _strength,
    _stamina,
    _agility,
    _mind,
    _will,
    _luck
};

enum class ELifeParams {
    _hp,
    _mp,
    _stamina_pts
};

enum class EExpParams {
    _level,
    _exp,
    _free_points
};

enum class EMoveParams {
    _move_speed,
    _cur_weight,
    _max_weight
};

enum class EHitParams {
    _atk_speed,
    _damage,
    _protection
};

enum class EPosParams {
    _x,
    _y,
    _time,
    _direction
};


const EMainParams EMainParam[] = {
    EMainParams::_strength, 
    EMainParams::_stamina, 
    EMainParams::_agility, 
    EMainParams::_mind, 
    EMainParams::_will, 
    EMainParams::_luck
};

const ELifeParams ELifeParam[] = {
    ELifeParams::_hp, 
    ELifeParams::_mp, 
    ELifeParams::_stamina_pts
};

const EMoveParams EMoveParam[] = {
    EMoveParams::_move_speed, 
    EMoveParams::_cur_weight, 
    EMoveParams::_max_weight
};

const EExpParams EExpParam[] = {
    EExpParams::_level, 
    EExpParams::_exp, 
    EExpParams::_free_points
};

const EHitParams EHitParam[] = {
    EHitParams::_atk_speed, 
    EHitParams::_damage, 
    EHitParams::_protection
};

const EPosParams EPosParam[] = {
    EPosParams::_x, 
    EPosParams::_y, 
    EPosParams::_time, 
    EPosParams::_direction
};


enum class EDirection {
    _stop,
    _left,
    _right,
    _up,
    _down
};


#endif // E_PARAMS_CATEGORIES_H
