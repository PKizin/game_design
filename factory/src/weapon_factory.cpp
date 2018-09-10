#include "weapon_factory.h"
#include "weapon_classifier.h"
#include "weapon.h"
#include "params.h"
#include "randomizer.h"


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

    const auto& weapon_type = static_cast< WeaponType >(classifier.get_type());
    const auto& weapon_level = Randomizer::dice_real(1, 10);
    
    params.set_exp_param(EExpParams::_level, weapon_level);

    if (weapon_type == WeaponType::_stick) 
    {
        const auto& strength = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& agility = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& stamina_pts = Randomizer::dice_real(weapon_level, weapon_level + 10) * 5.0;
        const auto& weight = Randomizer::dice_real(30, 50) / 10.0;
        const auto& atk_speed = Randomizer::dice_real(80, 110) / 100.0;
        const auto& min_damage = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& max_damage = min_damage + Randomizer::dice_real(0, 10);

        params.set_main_param(EMainParams::_strength, strength);
        params.set_main_param(EMainParams::_agility, agility);
        params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
        params.set_move_param(EMoveParams::_weight, weight);
        params.set_hit_param(EHitParams::_atk_speed, atk_speed);
        params.set_hit_param(EHitParams::_min_damage, min_damage);
        params.set_hit_param(EHitParams::_max_damage, max_damage);    
    } 
    else if (weapon_type == WeaponType::_dagger) 
    {
        const auto& agility = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& stamina_ptr = Randomizer::dice_real(weapon_level, weapon_level + 10) * 3.0;
        const auto& weight = Randomizer::dice_real(10, 30) / 10.0;
        const auto& atk_speed = Randomizer::dice_real(120, 150) / 100.0;
        const auto& min_damage = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& max_damage = min_damage + Randomizer::dice_real(0, 10);

        params.set_main_param(EMainParams::_agility, agility);
        params.set_life_param(ELifeParams::_stamina_pts, stamina_ptr);
        params.set_move_param(EMoveParams::_weight, weight);
        params.set_hit_param(EHitParams::_atk_speed, atk_speed);
        params.set_hit_param(EHitParams::_min_damage, min_damage);
        params.set_hit_param(EHitParams::_max_damage, max_damage);
    } 
    else if (weapon_type == WeaponType::_sword) 
    {
        const auto& agility = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& stamina_ptr = Randomizer::dice_real(weapon_level, weapon_level + 10) * 7.0;
        const auto& weight = Randomizer::dice_real(30, 70) / 10.0;
        const auto& atk_speed = Randomizer::dice_real(70, 100) / 100.0;
        const auto& min_damage = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& max_damage = min_damage + Randomizer::dice_real(0, 10);

        params.set_main_param(EMainParams::_strength, agility);
        params.set_life_param(ELifeParams::_stamina_pts, stamina_ptr);
        params.set_move_param(EMoveParams::_weight, weight);
        params.set_hit_param(EHitParams::_atk_speed, atk_speed);
        params.set_hit_param(EHitParams::_min_damage, min_damage);
        params.set_hit_param(EHitParams::_max_damage, max_damage);
    } 
    else if (weapon_type == WeaponType::_staff) 
    {
        const auto& mind = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& will = Randomizer::dice_real(weapon_level, weapon_level + 10);
        const auto& mp = Randomizer::dice_real(weapon_level, weapon_level + 10) * 5.0;
        const auto& weight = Randomizer::dice_real(40, 80) / 10.0;
        const auto& atk_speed = Randomizer::dice_real(30, 50) / 100.0;
        const auto& min_damage = Randomizer::dice_real(weapon_level, weapon_level + 10) * 2.0;
        const auto& max_damage = min_damage + Randomizer::dice_real(0, 10);

        params.set_main_param(EMainParams::_mind, mind);
        params.set_main_param(EMainParams::_will, will);
        params.set_life_param(ELifeParams::_mp, mp);
        params.set_move_param(EMoveParams::_weight, weight);
        params.set_hit_param(EHitParams::_atk_speed, atk_speed);
        params.set_hit_param(EHitParams::_min_damage, min_damage);
        params.set_hit_param(EHitParams::_max_damage, max_damage);
    }

    const auto& durability = Randomizer::dice_real(40, 100);
    const auto& max_durability = 100.0;

    params.set_hit_param(EHitParams::_durability, durability);
    params.set_hit_param(EHitParams::_max_durability, max_durability);
}

void WeaponFactory::build_item(IItem& item) const {
    WeaponClassifier cla;
    build_classifier(cla);

    Params par;
    build_params(cla, par);
    correct_params(cla, par);

    Params req;
    build_params(cla, req);
    correct_requirements(cla, req);

    item = Weapon(cla, par, req);
}


void WeaponFactory::correct_params(const IClassifier& classifier, IParams& params) const {
    params.set_exp_param(EExpParams::_level, 0.0);
}

void WeaponFactory::correct_requirements(const IClassifier& classifier, IParams& requirements) const {
    requirements.set_life_param(ELifeParams::_hp, 0.0);
    requirements.set_life_param(ELifeParams::_mp, 0.0);
    requirements.set_life_param(ELifeParams::_stamina_pts, 0.0);
    requirements.set_life_param(ELifeParams::_phys_protection, 0.0);
    requirements.set_life_param(ELifeParams::_mag_protection, 0.0);
    requirements.set_life_param(ELifeParams::_max_hp, 0.0);
    requirements.set_life_param(ELifeParams::_max_mp, 0.0);
    requirements.set_life_param(ELifeParams::_max_stamina_pts, 0.0);

    requirements.set_move_param(EMoveParams::_move_speed, 0.0);
    requirements.set_move_param(EMoveParams::_weight, 0.0);

    requirements.set_hit_param(EHitParams::_atk_speed, 0.0);
    requirements.set_hit_param(EHitParams::_min_damage, 0.0);
    requirements.set_hit_param(EHitParams::_max_damage, 0.0);
    requirements.set_hit_param(EHitParams::_durability, 0.0);
    requirements.set_hit_param(EHitParams::_max_durability, 0.0);
}

