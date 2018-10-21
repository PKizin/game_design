#include "potion_factory.hpp"
#include "potion_classifier.hpp"
#include "potion.hpp"
#include "params.hpp"
#include "randomizer.hpp"


void PotionFactory::build_item(IItem& item) const {
    PotionClassifier cla;
    build_classifier(cla);

    Params par;
    build_params(cla, par);
    correct_params(par);

    Params req;
    build_params(cla, req);
    correct_requirements(req);

    item = Potion(cla, par, req);
}

void PotionFactory::build_classifier(IClassifier& classifier) const {
    const auto& type = static_cast< PotionType >(Randomizer::dice_int(PotionType::_NONE + 1, PotionType::_MAX - 1));
    const auto& prop1 = static_cast< PotionProperty1 >(Randomizer::dice_int(PotionProperty1::_NONE + 1, PotionProperty1::_MAX - 1));
    classifier = PotionClassifier(type, prop1);
}

void PotionFactory::build_params(const IClassifier& classifier, IParams& params) const {
    params = Params();

    const auto& type = static_cast< PotionType >(classifier.get_type());
    const auto& prop1 = static_cast< PotionProperty1 >(classifier.get_property1());

    switch (type)
    {
        case PotionType::_hp:
            build_params_hp(prop1, params);
            break;

        case PotionType::_mp:
            build_params_mp(prop1, params);
            break;

        case PotionType::_exp:
            build_params_exp(prop1, params);
            break;
        
        default:
            break;
    }
}

void PotionFactory::build_params_hp(PotionProperty1 prop1, IParams& params) const {

}

void PotionFactory::build_params_mp(PotionProperty1 prop1, IParams& params) const {

}

void PotionFactory::build_params_exp(PotionProperty1 prop1, IParams& params) const {

}

float PotionFactory::coeff_property1(PotionProperty1 prop1) const {
    auto coeff = 1.0;
    if (prop1 == PotionProperty1::_big)
    {
        coeff = 1.5;
    }
    else if (prop1 == PotionProperty1::_small)
    {
        coeff = 0.5;
    }
    return coeff;
}

void PotionFactory::correct_params(IParams& par) const {
    par.set_exp_param(EExpParams::_level, 0.0);

    par.set_move_param(EMoveParams::_weight, 0.0);
    
    par.set_hit_param(EHitParams::_durability, 0.0);
    par.set_hit_param(EHitParams::_max_durability, 0.0);

    par.set_pos_param(EPosParams::_direction, 0.0);
}

void PotionFactory::correct_requirements(IParams& req) const {
    req.set_main_param(EMainParams::_strength, 0.0);
    req.set_main_param(EMainParams::_stamina, 0.0);
    req.set_main_param(EMainParams::_agility, 0.0);
    req.set_main_param(EMainParams::_mind, 0.0);
    req.set_main_param(EMainParams::_will, 0.0);
    req.set_main_param(EMainParams::_luck, 0.0);

    req.set_life_param(ELifeParams::_hp, 0.0);
    req.set_life_param(ELifeParams::_mp, 0.0);
    req.set_life_param(ELifeParams::_stamina_pts, 0.0);
    req.set_life_param(ELifeParams::_phys_protection, 0.0);
    req.set_life_param(ELifeParams::_mag_protection, 0.0);
    req.set_life_param(ELifeParams::_max_hp, 0.0);
    req.set_life_param(ELifeParams::_max_mp, 0.0);
    req.set_life_param(ELifeParams::_max_stamina_pts, 0.0);

    // level might be required
    req.set_exp_param(EExpParams::_exp, 0.0);
    req.set_exp_param(EExpParams::_free_points, 0.0);

    req.set_move_param(EMoveParams::_move_speed, 0.0);
    req.set_move_param(EMoveParams::_weight, 0.0);
    req.set_move_param(EMoveParams::_max_weight, 0.0);

    req.set_hit_param(EHitParams::_atk_speed, 0.0);
    req.set_hit_param(EHitParams::_min_damage, 0.0);
    req.set_hit_param(EHitParams::_max_damage, 0.0);
    req.set_hit_param(EHitParams::_durability, 0.0);
    req.set_hit_param(EHitParams::_max_durability, 0.0);

    req.set_pos_param(EPosParams::_x, 0.0);
    req.set_pos_param(EPosParams::_y, 0.0);
    req.set_pos_param(EPosParams::_time, 0.0);
    req.set_pos_param(EPosParams::_direction, 0.0);
}

