#include "weapon_factory.h"
#include "weapon_classifier.h"
#include "weapon.h"
#include "params.h"
#include "randomizer.h"


void WeaponFactory::build_classifier(IClassifier& classifier) const {
    classifier = WeaponClassifier(
        static_cast< EWeaponType >(Randomizer::dice( static_cast<int>(EWeaponType::_none) + 1, static_cast<int>(EWeaponType::_staff) )),
        static_cast< EWeaponMaterial >(Randomizer::dice( static_cast<int>(EWeaponMaterial::_none) + 1, static_cast<int>(EWeaponMaterial::_glass) )),
        static_cast< EWeaponProperty1 >(Randomizer::dice( static_cast<int>(EWeaponProperty1::_none) + 1, static_cast<int>(EWeaponProperty1::_two_handed) ))
    );
}

void WeaponFactory::build_params(IParams& params) const
{
    // TODO: params must depend on EExpParams::_level

    params = Params();

    params.set_main_param(EMainParams::_strength, static_cast<float>(Randomizer::dice(0, 5)));
    params.set_main_param(EMainParams::_stamina, static_cast<float>(Randomizer::dice(0, 5)));
    params.set_main_param(EMainParams::_agility, static_cast<float>(Randomizer::dice(0, 5)));
    params.set_main_param(EMainParams::_mind, static_cast<float>(Randomizer::dice(0, 5)));
    params.set_main_param(EMainParams::_will, static_cast<float>(Randomizer::dice(0, 5)));
    params.set_main_param(EMainParams::_luck, static_cast<float>(Randomizer::dice(0, 5)));

    params.set_life_param(ELifeParams::_hp, static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_mp, static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_stamina_pts, static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_phys_protection, static_cast<float>(Randomizer::dice(0, 10)));
    params.set_life_param(ELifeParams::_mag_protection, static_cast<float>(Randomizer::dice(0, 10)));
    params.set_life_param(ELifeParams::_max_hp, params.get_life_param(ELifeParams::_hp) + static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_max_mp, params.get_life_param(ELifeParams::_mp) + static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_max_stamina_pts, params.get_life_param(ELifeParams::_stamina_pts) + static_cast<float>(Randomizer::dice(0, 100)));

    params.set_move_param(EMoveParams::_move_speed, static_cast<float>(Randomizer::dice(0, 20)));
    params.set_move_param(EMoveParams::_weight, static_cast<float>(Randomizer::dice(0, 5)));

    params.set_exp_param(EExpParams::_level, static_cast<float>(Randomizer::dice(1, 10)));

    params.set_hit_param(EHitParams::_atk_speed, static_cast<float>(Randomizer::dice(0, 20)));
    params.set_hit_param(EHitParams::_min_damage, static_cast<float>(Randomizer::dice(1, 10)));
    params.set_hit_param(EHitParams::_max_damage, params.get_hit_param(EHitParams::_min_damage) + static_cast<float>(Randomizer::dice(0, 10)));
    params.set_hit_param(EHitParams::_durability, static_cast<float>(Randomizer::dice(0, 100)));
    params.set_hit_param(EHitParams::_max_durability, 100.0);
}

void WeaponFactory::build_item(IItem& item) const
{
    WeaponClassifier cla;
    IClassifier& ref_cla = cla;
    build_classifier(ref_cla);

    Params par;
    IParams& ref_par = par;
    build_params(ref_par);
    correct_params(ref_par);

    Params req;
    IParams& ref_req = req;
    build_params(ref_req);
    correct_requirements(ref_req);

    item = Weapon(ref_cla, ref_par, ref_req);
}


void WeaponFactory::correct_params(IParams& params) const {
    params.set_exp_param(EExpParams::_level, 0.0);
}

void WeaponFactory::correct_requirements(IParams& requirements) const {
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

