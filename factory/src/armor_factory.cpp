#include "armor_factory.h"
#include "armor_classifier.h"
#include "armor.h"
#include "params.h"
#include "randomizer.h"


void ArmorFactory::build_item(IItem& item) const {
    ArmorClassifier cla;
    build_classifier(cla);

    Params par;
    build_params(cla, par);
    correct_params(par);

    Params req;
    build_params(cla, req);
    correct_requirements(req);

    item = Armor(cla, par, req);
}

void ArmorFactory::build_classifier(IClassifier& classifier) const {
    const auto& type = static_cast< ArmorType >(Randomizer::dice_int(ArmorType::_NONE + 1, ArmorType::_MAX - 1));
    const auto& mat = static_cast< ArmorMaterial >(Randomizer::dice_int(ArmorMaterial::_NONE + 1, ArmorMaterial::_MAX - 1));

    classifier = ArmorClassifier(type, mat);
}

void ArmorFactory::build_params(const IClassifier& classifier, IParams& params) const {
    params = Params();

    const auto& type = static_cast< ArmorType >(classifier.get_type());
    const auto& mat = static_cast< ArmorMaterial >(classifier.get_material());
    
    const auto& lvl = Randomizer::dice_real(1, 10);
    const auto& dur = Randomizer::dice_real(40, 100);
    const auto& max_dur = 100.0;

    params.set_exp_param(EExpParams::_level, lvl);
    params.set_hit_param(EHitParams::_durability, dur);
    params.set_hit_param(EHitParams::_max_durability, max_dur);

    switch (type)
    {
        case ArmorType::_head:
            build_params_head(lvl, mat, params);
            break;

        case ArmorType::_shoulders:
            build_params_shoulders(lvl, mat, params);
            break;

        case ArmorType::_chest:
            build_params_chest(lvl, mat, params);
            break;

        case ArmorType::_hands:
            build_params_hands(lvl, mat, params);
            break;

        case ArmorType::_belt:
            build_params_belt(lvl, mat, params);
            break;

        case ArmorType::_legs:
            build_params_legs(lvl, mat, params);
            break;

        case ArmorType::_feet:
            build_params_feet(lvl, mat, params);
            break;

        default:
            break;
    }
}

void ArmorFactory::build_params_head(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(3, 8) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(5, 12) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(15, 25) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(10, 18) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

void ArmorFactory::build_params_shoulders(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 5.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(4, 9) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 5.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(7, 14) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 5.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(18, 28) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 5.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(12, 20) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

void ArmorFactory::build_params_chest(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 8.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(15, 20) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 8.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(18, 24) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 10);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 10);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 8.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(35, 45) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 8.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(20, 30) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

void ArmorFactory::build_params_hands(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(2, 4) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(3, 5) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(5, 10) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(4, 8) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

void ArmorFactory::build_params_belt(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(2, 5) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(4, 8) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(8, 15) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 4.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(6, 12) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

void ArmorFactory::build_params_legs(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 6.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(5, 10) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 6.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(8, 15) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 6.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(15, 25) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 6.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(10, 20) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

void ArmorFactory::build_params_feet(float level, ArmorMaterial material, IParams& params) const {
    const auto& coeff_mat = coeff_material(material);
    const auto& coeff_mat_inv = 1.0 / coeff_mat;

    auto strength = 0.0;
    auto stamina = 0.0;
    auto agility = 0.0;
    auto mind = 0.0;
    auto will = 0.0;
    auto luck = 0.0;

    auto hp = 0.0;
    auto mp = 0.0;
    auto stamina_pts = 0.0;
    auto phys_protection = 0.0;
    auto move_speed = 0.0;
    auto weight = 0.0;

    switch (material)
    {
        case ArmorMaterial::_rags:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            luck = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(2, 4) / 10.0;
            break;

        case ArmorMaterial::_cotton:
            mind = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            will = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            mp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(3, 6) / 10.0;
            break;

        case ArmorMaterial::_mail:
            strength = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            hp = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 120, level + 150) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 30, level + 50) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(5, 10) / 10.0;
            break;

        case ArmorMaterial::_leather:
            agility = (coeff_mat_inv) * Randomizer::dice_real(level, level + 3);
            stamina = (coeff_mat) * Randomizer::dice_real(level, level + 3);
            stamina_pts = (coeff_mat) * Randomizer::dice_real(level, level + 10) * 3.0;
            phys_protection = (coeff_mat) * Randomizer::dice_real(level + 80, level + 110) / 100.0;
            move_speed = (coeff_mat_inv) * Randomizer::dice_real(level + 70, level + 100) / 100.0;
            weight = (coeff_mat) * Randomizer::dice_real(4, 8) / 10.0;
            break;

        default:
            break;
    }

    params.set_main_param(EMainParams::_strength, strength);
    params.set_main_param(EMainParams::_stamina, stamina);
    params.set_main_param(EMainParams::_agility, agility);
    params.set_main_param(EMainParams::_mind, mind);
    params.set_main_param(EMainParams::_will, will);
    params.set_main_param(EMainParams::_luck, luck);

    params.set_life_param(ELifeParams::_hp, hp);
    params.set_life_param(ELifeParams::_mp, mp);
    params.set_life_param(ELifeParams::_stamina_pts, stamina_pts);
    params.set_life_param(ELifeParams::_phys_protection, phys_protection);
    params.set_move_param(EMoveParams::_move_speed, move_speed);
    params.set_move_param(EMoveParams::_weight, weight);
}

float ArmorFactory::coeff_material(ArmorMaterial material) const {
    auto coeff = 1.0;
    if (material == ArmorMaterial::_rags)
    {
        coeff = 0.7;
    }
    else if (material == ArmorMaterial::_cotton)
    {
        coeff = 0.8;
    }
    else if (material == ArmorMaterial::_leather)
    {
        coeff = 0.9;
    }
    return coeff;
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

