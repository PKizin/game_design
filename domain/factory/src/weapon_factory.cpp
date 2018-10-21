#include "weapon_factory.hpp"
#include "weapon_classifier.hpp"
#include "weapon.hpp"
#include "params.hpp"
#include "randomizer.hpp"


void WeaponFactory::build_item(IItem& item) const {
    WeaponClassifier cla;
    build_classifier(cla);

    Params par;
    build_params(cla, par);
    correct_params(par);

    Params req;
    build_params(cla, req);
    correct_requirements(req);

    item = Weapon(cla, par, req);
}

void WeaponFactory::build_classifier(IClassifier& classifier) const {
    const auto& type = static_cast< WeaponType >(Randomizer::dice_int(WeaponType::_NONE + 1, WeaponType::_MAX - 1));
    const auto& mat = static_cast< WeaponMaterial >(Randomizer::dice_int(WeaponMaterial::_NONE + 1, WeaponMaterial::_MAX - 1));
    WeaponProperty1 prop1;
    if (type == WeaponType::_dagger) 
    {
        prop1 = WeaponProperty1::_one_handed;
    } 
    else 
    {
        prop1 = static_cast< WeaponProperty1 >(Randomizer::dice_int(WeaponProperty1::_NONE + 1, WeaponProperty1::_MAX - 1));
    }

    classifier = WeaponClassifier(type, mat, prop1);
}

void WeaponFactory::build_params(const IClassifier& classifier, IParams& params) const {
    params = Params();

    const auto& type = static_cast< WeaponType >(classifier.get_type());
    const auto& mat = static_cast< WeaponMaterial >(classifier.get_material());
    const auto& prop1 = static_cast< WeaponProperty1 >(classifier.get_property1());

    const auto& lvl = Randomizer::dice_real(1, 10);
    const auto& dur = Randomizer::dice_real(40, 100);
    const auto& max_dur = 100.0;
    
    params.set_exp_param(EExpParams::_level, lvl);
    params.set_hit_param(EHitParams::_durability, dur);
    params.set_hit_param(EHitParams::_max_durability, max_dur);

    switch (type)
    {
        case WeaponType::_stick:
            build_params_stick(lvl, mat, prop1, params);
            break;

        case WeaponType::_dagger:
            build_params_dagger(lvl, mat, prop1, params);
            break;
        
        case WeaponType::_sword:
            build_params_sword(lvl, mat, prop1, params);
            break;

        case WeaponType::_staff:
            build_params_staff(lvl, mat, prop1, params);
            break;

        default:
            break;
    }
}

void WeaponFactory::build_params_stick(float level, WeaponMaterial material, WeaponProperty1 property1, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_prop1 = coeff_property1(property1);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;
    const auto& coeff_prop1_inv = 1.0 / coeff_prop1;

    const auto& strength = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 3);
    const auto& agility = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level, level + 3);
    const auto& stamina_pts = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level, level + 10) * 0.5;
    const auto& weight = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(30, 50) / 10.0;
    const auto& atk_speed = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
    const auto& min_damage = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 10);
    const auto& max_damage = min_damage + (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(0, 10);

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_move_param(EMoveParams::_weight, weight);
    params.set_hit_param(EHitParams::_atk_speed, atk_speed);
    params.set_hit_param(EHitParams::_min_damage, min_damage);
    params.set_hit_param(EHitParams::_max_damage, max_damage);
}

void WeaponFactory::build_params_dagger(float level, WeaponMaterial material, WeaponProperty1 property1, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_prop1 = coeff_property1(property1);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;
    const auto& coeff_prop1_inv = 1.0 / coeff_prop1;

    const auto& agility = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level, level + 3);
    const auto& stamina_pts = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level, level + 10) * 0.3;
    const auto& weight = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(10, 30) / 10.0;
    const auto& atk_speed = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
    const auto& min_damage = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 10);
    const auto& max_damage = min_damage + (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(0, 10);

    params.set_main_param(EMainParams::_agility, agility);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_move_param(EMoveParams::_weight, weight);
    params.set_hit_param(EHitParams::_atk_speed, atk_speed);
    params.set_hit_param(EHitParams::_min_damage, min_damage);
    params.set_hit_param(EHitParams::_max_damage, max_damage);
}

void WeaponFactory::build_params_sword(float level, WeaponMaterial material, WeaponProperty1 property1, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_prop1 = coeff_property1(property1);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;
    const auto& coeff_prop1_inv = 1.0 / coeff_prop1;

    const auto& strength = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 3);
    const auto& stamina_pts = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level, level + 10) * 0.7;
    const auto& weight = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(30, 70) / 10.0;
    const auto& atk_speed = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
    const auto& min_damage = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 10);
    const auto& max_damage = min_damage + (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(0, 10);

    params.set_main_param(EMainParams::_strength, strength);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_move_param(EMoveParams::_weight, weight);
    params.set_hit_param(EHitParams::_atk_speed, atk_speed);
    params.set_hit_param(EHitParams::_min_damage, min_damage);
    params.set_hit_param(EHitParams::_max_damage, max_damage);
}

void WeaponFactory::build_params_staff(float level, WeaponMaterial material, WeaponProperty1 property1, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_prop1 = coeff_property1(property1);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;
    const auto& coeff_prop1_inv = 1.0 / coeff_prop1;

    const auto& mind = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 3);
    const auto& will = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 3);
    const auto& mp = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 10) * 0.5;
    const auto& weight = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(40, 80) / 10.0;
    const auto& atk_speed = (coeff_mat_inv) * (coeff_prop1_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
    const auto& min_damage = (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(level, level + 10) * 2.0;
    const auto& max_damage = min_damage + (coeff_mat) * (coeff_prop1) * Randomizer::dice_real(0, 10);

    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_move_param(EMoveParams::_weight, weight);
    params.set_hit_param(EHitParams::_atk_speed, atk_speed);
    params.set_hit_param(EHitParams::_min_damage, min_damage);
    params.set_hit_param(EHitParams::_max_damage, max_damage);
}

float WeaponFactory::coeff_material(WeaponMaterial material) const {
    auto coeff = 1.0;
    if (material == WeaponMaterial::_wood) 
    {
        coeff = 0.8;
    }
    else if (material == WeaponMaterial::_glass)
    {
        coeff = 0.9;
    }
    return coeff;
}

float WeaponFactory::coeff_property1(WeaponProperty1 property1) const {
    auto coeff = 1.0;
    if (property1 == WeaponProperty1::_one_handed)
    {
        coeff = 0.75;
    }
    return coeff;
}

void WeaponFactory::correct_params(IParams& par) const {
    par.set_exp_param(EExpParams::_level, 0.0);

    par.set_life_param(ELifeParams::_hp, 0.0);
    par.set_life_param(ELifeParams::_mp, 0.0);
    par.set_life_param(ELifeParams::_stamina_pts, 0.0);
}

void WeaponFactory::correct_requirements(IParams& req) const {
    req.set_life_param(ELifeParams::_hp, 0.0);
    req.set_life_param(ELifeParams::_phys_protection, 0.0);
    req.set_life_param(ELifeParams::_mag_protection, 0.0);
    req.set_life_param(ELifeParams::_max_hp, 0.0);
    req.set_life_param(ELifeParams::_max_mp, 0.0);
    req.set_life_param(ELifeParams::_max_stamina_pts, 0.0);

    req.set_move_param(EMoveParams::_move_speed, 0.0);
    req.set_move_param(EMoveParams::_weight, 0.0);

    req.set_hit_param(EHitParams::_atk_speed, 0.0);
    req.set_hit_param(EHitParams::_min_damage, 0.0);
    req.set_hit_param(EHitParams::_max_damage, 0.0);
    req.set_hit_param(EHitParams::_durability, 0.0);
    req.set_hit_param(EHitParams::_max_durability, 0.0);
}

