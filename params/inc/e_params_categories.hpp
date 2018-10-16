#ifndef E_PARAMS_CATEGORIES_H
#define E_PARAMS_CATEGORIES_H

#include <string>


enum EMainParams {
    _strength,
    _stamina,
    _agility,
    _mind,
    _will,
    _luck,
};

enum ELifeParams {
    _hp,
    _mp,
    _stamina_pts,
    _phys_protection,
    _mag_protection,
    _max_hp,
    _max_mp,
    _max_stamina_pts
};

enum EExpParams {
    _level,
    _exp,
    _free_points
};

enum EMoveParams {
    _move_speed,
    _weight,
    _max_weight
};

enum EHitParams {
    _atk_speed,
    _min_damage,
    _max_damage,
    _durability,
    _max_durability
};

enum EPosParams {
    _x,
    _y,
    _time,
    _direction
};

enum EDirection {
    _stop,
    _left,
    _right,
    _up,
    _down
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
    ELifeParams::_stamina_pts,
    ELifeParams::_phys_protection,
    ELifeParams::_mag_protection,
    ELifeParams::_max_hp,
    ELifeParams::_max_mp,
    ELifeParams::_max_stamina_pts
};

const EMoveParams EMoveParam[] = {
    EMoveParams::_move_speed, 
    EMoveParams::_weight, 
    EMoveParams::_max_weight
};

const EExpParams EExpParam[] = {
    EExpParams::_level, 
    EExpParams::_exp, 
    EExpParams::_free_points
};

const EHitParams EHitParam[] = {
    EHitParams::_atk_speed, 
    EHitParams::_min_damage,
    EHitParams::_max_damage, 
    EHitParams::_durability,
    EHitParams::_max_durability
};

const EPosParams EPosParam[] = {
    EPosParams::_x, 
    EPosParams::_y, 
    EPosParams::_time, 
    EPosParams::_direction
};


#endif // E_PARAMS_CATEGORIES_H
