#include "armor_factory.h"
#include "armor_classifier.h"
#include "armor.h"
#include "params.h"
#include "randomizer.h"


void ArmorFactory::build_classifier(IClassifier& classifier) const {
    EArmorType type = static_cast< EArmorType >(Randomizer::dice( static_cast<int>(EArmorType::_none) + 1, static_cast<int>(EArmorType::_feet) ));
    EArmorMaterial mat = static_cast< EArmorMaterial >(Randomizer::dice( static_cast<int>(EArmorMaterial::_none) + 1, static_cast<int>(EArmorMaterial::_leather) ));

    classifier = ArmorClassifier(type, mat);
}

void ArmorFactory::build_params(IParams& params) const
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
    params.set_life_param(ELifeParams::_phys_protection, static_cast<float>(Randomizer::dice(0, 100)) / 100.0);
    params.set_life_param(ELifeParams::_mag_protection, static_cast<float>(Randomizer::dice(0, 100)) / 100.0);
    params.set_life_param(ELifeParams::_max_hp, params.get_life_param(ELifeParams::_hp) + static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_max_mp, params.get_life_param(ELifeParams::_mp) + static_cast<float>(Randomizer::dice(0, 100)));
    params.set_life_param(ELifeParams::_max_stamina_pts, params.get_life_param(ELifeParams::_stamina_pts) + static_cast<float>(Randomizer::dice(0, 100)));

    params.set_move_param(EMoveParams::_move_speed, static_cast<float>(Randomizer::dice(50, 150)) / 100.0);
    params.set_move_param(EMoveParams::_weight, static_cast<float>(Randomizer::dice(10, 50)) / 10.0);

    params.set_exp_param(EExpParams::_level, static_cast<float>(Randomizer::dice(1, 10)));

    params.set_hit_param(EHitParams::_durability, static_cast<float>(Randomizer::dice(40, 100)));
    params.set_hit_param(EHitParams::_max_durability, 100.0);
}

void ArmorFactory::build_item(IItem& item) const
{
    ArmorClassifier cla;
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

    item = Armor(ref_cla, ref_par, ref_req);
}


void ArmorFactory::correct_params(IParams& params) const {
    params.set_exp_param(EExpParams::_level, 0.0);
}

void ArmorFactory::correct_requirements(IParams& requirements) const {
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

    requirements.set_hit_param(EHitParams::_durability, 0.0);
    requirements.set_hit_param(EHitParams::_max_durability, 0.0);
}

