#include "armor.h"
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
    const char tab = '\t';
    const char end_line = '\n';
    const std::string end_section = "\n\n";

    const std::vector< std::string > class_tags = { "none", "weapon", "armor", "jewerly", "potion" };
    const std::vector< std::string > type_tags = { "none", "head", "shoulders", "chest", "hands", "belt", "legs", "feet" };
    const std::vector< std::string > material_tags = { "none", "rags", "cotton", "mail", "leather" };

    const int cur_durability = static_cast<int>(_params.get_hit_param(EHitParams::_durability));
    const int max_durability = static_cast<int>(_params.get_hit_param(EHitParams::_max_durability));

    std::cout << "+--------------+" << end_line;
    std::cout << "|     item     |" << end_line;
    std::cout << "+--------------+" << end_line;

    std::cout << "classifier:" << end_line;
    std::cout << tab << "class    : " << class_tags[ _classifier.get_class() ] << end_line;
    std::cout << tab << "type     : " << type_tags[ _classifier.get_type() ] << end_line;
    std::cout << tab << "material : " << material_tags[ _classifier.get_material() ] << end_section;

    std::cout << "params:" << end_line;
    std::cout << tab << "phys. protection : " << _params.get_life_param(ELifeParams::_phys_protection) << end_line;
    std::cout << tab << "mag. protection  : " << _params.get_life_param(ELifeParams::_mag_protection) << end_line;
    std::cout << tab << "durability       : " << cur_durability << '(' << max_durability << ')' << end_line;
    std::cout << tab << "weight           : " << _params.get_move_param(EMoveParams::_weight) << end_section;
    
    std::cout << "requirements:" << end_line;
    std::cout << tab << "level    : " << static_cast<int>(_requirements.get_exp_param(EExpParams::_level)) << end_line;
    std::cout << tab << "strength : " << static_cast<int>(_requirements.get_main_param(EMainParams::_strength)) << end_line;
    std::cout << tab << "stamina  : " << static_cast<int>(_requirements.get_main_param(EMainParams::_stamina)) << end_line;
    std::cout << tab << "agility  : " << static_cast<int>(_requirements.get_main_param(EMainParams::_agility)) << end_line;
    std::cout << tab << "mind     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_mind)) << end_line;
    std::cout << tab << "will     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_will)) << end_line;
    std::cout << tab << "luck     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_luck)) << end_section;
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
