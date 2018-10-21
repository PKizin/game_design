#include "armor.hpp"
#include <vector>


Armor::Armor(const IClassifier& classifier, const IParams& params, const IParams& requirements) :
    IItem(),
    _classifier( classifier ),
    _params( params ),
    _requirements( requirements )
{
}


void Armor::get_classifier(IClassifier& classifier) const {
    classifier = ArmorClassifier( _classifier );
}

void Armor::get_params(IParams& params) const {
    params = Params( _params );
}

void Armor::get_requirements(IParams& requirements) const {
    requirements = Params( _requirements );
}


void Armor::set_classifier(const IClassifier& classifier) {
    _classifier = ArmorClassifier( classifier );
}

void Armor::set_params(const IParams& params) {
    _params = Params( params );
}

void Armor::set_requirements(const IParams& requirements) {
    _requirements = Params( requirements );
}


void Armor::broke(float damage) {
    float durability = _params.get_hit_param(EHitParams::_durability);
    _params.set_hit_param(EHitParams::_durability, durability - damage);
}

void Armor::repair() {
    float max_durability = _params.get_hit_param(EHitParams::_max_durability);
    _params.set_hit_param(EHitParams::_durability, max_durability);
}


void Armor::print() const {
    const auto& tab = '\t';
    const auto& end_line = '\n';
    const auto& end_section = "\n\n";

    const std::vector< std::string > class_tags = { "none", "weapon", "armor", "jewerly", "potion" };
    const std::vector< std::string > type_tags = { "none", "head", "shoulders", "chest", "hands", "belt", "legs", "feet" };
    const std::vector< std::string > material_tags = { "none", "rags", "cotton", "mail", "leather" };

    const auto& cur_durability = static_cast<int>(_params.get_hit_param(EHitParams::_durability));
    const auto& max_durability = static_cast<int>(_params.get_hit_param(EHitParams::_max_durability));
    const auto& hp = static_cast<int>(_params.get_life_param(ELifeParams::_hp));
    const auto& mp = static_cast<int>(_params.get_life_param(ELifeParams::_mp));
    const auto& stamina_pts = static_cast<int>(_params.get_life_param(ELifeParams::_stamina_pts));
    const auto& phys_protection = _params.get_life_param(ELifeParams::_phys_protection);
    const auto& mag_protection = _params.get_life_param(ELifeParams::_mag_protection);
    const auto& move_speed = _params.get_move_param(EMoveParams::_move_speed);
    const auto& weight = _params.get_move_param(EMoveParams::_weight);

    const auto& level = static_cast<int>(_requirements.get_exp_param(EExpParams::_level));
    const auto& strength = static_cast<int>(_requirements.get_main_param(EMainParams::_strength));
    const auto& stamina = static_cast<int>(_requirements.get_main_param(EMainParams::_stamina));
    const auto& agility = static_cast<int>(_requirements.get_main_param(EMainParams::_agility));
    const auto& mind = static_cast<int>(_requirements.get_main_param(EMainParams::_mind));
    const auto& will = static_cast<int>(_requirements.get_main_param(EMainParams::_will));
    const auto& luck = static_cast<int>(_requirements.get_main_param(EMainParams::_luck));


    std::cout << end_line;
    std::cout << "+--------------+" << end_line;
    std::cout << "|     item     |" << end_line;
    std::cout << "+--------------+" << end_line;

    std::cout << "classifier:" << end_line;
    std::cout << tab << "class    : " << class_tags[ _classifier.get_class() ] << end_line;
    std::cout << tab << "type     : " << type_tags[ _classifier.get_type() ] << end_line;
    std::cout << tab << "material : " << material_tags[ _classifier.get_material() ] << end_section;

    std::cout << "params:" << end_line;
    if (hp)
        std::cout << tab << "hp               : " << hp << end_line;
    if (mp)
        std::cout << tab << "mp               : " << mp << end_line;
    if (stamina_pts)
        std::cout << tab << "stamina pts      : " << stamina_pts << end_line;
    if (phys_protection)
        std::cout << tab << "phys. protection : " << phys_protection << end_line;
    if (mag_protection)
        std::cout << tab << "mag. protection  : " << mag_protection << end_line;
    if (move_speed)
        std::cout << tab << "move speed       : " << move_speed << end_line;
    std::cout << tab << "durability       : " << cur_durability << '(' << max_durability << ')' << end_line;
    std::cout << tab << "weight           : " << weight << end_section;
    
    std::cout << "requirements:" << end_line;
    std::cout << tab << "level    : " << level << end_line;
    if (strength)
        std::cout << tab << "strength : " << strength << end_line;
    if (stamina)
        std::cout << tab << "stamina  : " << stamina << end_line;
    if (agility)
        std::cout << tab << "agility  : " << agility << end_line;
    if (mind)
        std::cout << tab << "mind     : " << mind << end_line;
    if (will)
        std::cout << tab << "will     : " << will << end_line;
    if (luck)
        std::cout << tab << "luck     : " << luck << end_section;
}


IItem& Armor::operator=(const IItem& other) {
    return operator=( static_cast< const Armor& >(other) );
}

Armor& Armor::operator=(const Armor& other) {
    _classifier = other._classifier;
    _params = other._params;
    _requirements = other._requirements;
    return *this;
}
