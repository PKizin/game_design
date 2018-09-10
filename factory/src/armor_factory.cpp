#include "armor_factory.h"
#include "armor_classifier.h"
#include "armor.h"
#include "params.h"
#include "randomizer.h"


void ArmorFactory::build_classifier(IClassifier& classifier) const {
    auto type = static_cast< ArmorType >(Randomizer::dice_int(ArmorType::_NONE + 1, ArmorType::_MAX - 1));
    auto mat = static_cast< ArmorMaterial >(Randomizer::dice_int(ArmorMaterial::_NONE + 1, ArmorMaterial::_MAX - 1));

    classifier = ArmorClassifier(type, mat);
}

void ArmorFactory::build_params(const IClassifier& classifier, IParams& params) const {
    
    // TODO: params must depend on EExpParams::_level

    params = Params();

    params.set_main_param(EMainParams::_strength, Randomizer::dice_real(0, 5));
    params.set_main_param(EMainParams::_stamina, Randomizer::dice_real(0, 5));
    params.set_main_param(EMainParams::_agility, Randomizer::dice_real(0, 5));
    params.set_main_param(EMainParams::_mind, Randomizer::dice_real(0, 5));
    params.set_main_param(EMainParams::_will, Randomizer::dice_real(0, 5));
    params.set_main_param(EMainParams::_luck, Randomizer::dice_real(0, 5));

    params.set_life_param(ELifeParams::_hp, Randomizer::dice_real(0, 100));
    params.set_life_param(ELifeParams::_mp, Randomizer::dice_real(0, 100));
    params.set_life_param(ELifeParams::_stamina_pts, Randomizer::dice_real(0, 100));
    params.set_life_param(ELifeParams::_phys_protection, Randomizer::dice_real(0, 100) / 100.0);
    params.set_life_param(ELifeParams::_mag_protection, Randomizer::dice_real(0, 100) / 100.0);
    params.set_life_param(ELifeParams::_max_hp, params.get_life_param(ELifeParams::_hp) + Randomizer::dice_real(0, 100));
    params.set_life_param(ELifeParams::_max_mp, params.get_life_param(ELifeParams::_mp) + Randomizer::dice_real(0, 100));
    params.set_life_param(ELifeParams::_max_stamina_pts, params.get_life_param(ELifeParams::_stamina_pts) + Randomizer::dice_real(0, 100));

    params.set_move_param(EMoveParams::_move_speed, Randomizer::dice_real(50, 150) / 100.0);
    params.set_move_param(EMoveParams::_weight, Randomizer::dice_real(10, 50) / 10.0);

    params.set_exp_param(EExpParams::_level, Randomizer::dice_real(1, 10));

    params.set_hit_param(EHitParams::_durability, Randomizer::dice_real(40, 100));
    params.set_hit_param(EHitParams::_max_durability, 100.0);
}

void ArmorFactory::build_item(IItem& item) const {
    ArmorClassifier cla;
    build_classifier(cla);

    Params par;
    build_params(cla, par);
    correct_params(cla, par);

    Params req;
    build_params(cla, req);
    correct_requirements(cla, req);

    item = Armor(cla, par, req);
}


void ArmorFactory::correct_params(const IClassifier& classifier, IParams& params) const {
    params.set_exp_param(EExpParams::_level, 0.0);
}

void ArmorFactory::correct_requirements(const IClassifier& classifier, IParams& requirements) const {
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

