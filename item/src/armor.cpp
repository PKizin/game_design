#include "armor.h"


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
    std::cout << "+--------------+\n";
    std::cout << "|     item     |\n";
    std::cout << "+--------------+\n";
     
    _classifier.print();

    std::cout << "params:\n";
    std::cout << "\tphys. protection : " << _params.get_life_param(ELifeParams::_phys_protection) << '\n';
    std::cout << "\tmag. protection  : " << _params.get_life_param(ELifeParams::_mag_protection) << '\n';
    std::cout << "\tdurability       : " << static_cast<int>(_params.get_hit_param(EHitParams::_durability));
    std::cout << '(' << static_cast<int>(_params.get_hit_param(EHitParams::_max_durability)) << ")\n";
    std::cout << "\tweight           : " << _params.get_move_param(EMoveParams::_weight) << "\n\n";
    
    std::cout << "requirements:\n";
    std::cout << "\tlevel    : " << static_cast<int>(_requirements.get_exp_param(EExpParams::_level)) << '\n';
    std::cout << "\tstrength : " << static_cast<int>(_requirements.get_main_param(EMainParams::_strength)) << '\n';
    std::cout << "\tstamina  : " << static_cast<int>(_requirements.get_main_param(EMainParams::_stamina)) << '\n';
    std::cout << "\tagility  : " << static_cast<int>(_requirements.get_main_param(EMainParams::_agility)) << '\n';
    std::cout << "\tmind     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_mind)) << '\n';
    std::cout << "\twill     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_will)) << '\n';
    std::cout << "\tluck     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_luck)) << "\n\n";
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
