#include "weapon.h"


Weapon::Weapon(const IClassifier& classifier, const IParams& params, const IParams& requirements) : 
    IItem(),
    _classifier( classifier ),
    _params( params ),
    _requirements( requirements )
{
}


void Weapon::get_classifier(IClassifier& classifier) const {
    classifier = WeaponClassifier( _classifier );
}

void Weapon::get_params(IParams& params) const {
    params = Params( _params );
}

void Weapon::get_requirements(IParams& requirements) const {
    requirements = Params( _requirements );
}


void Weapon::set_classifier(const IClassifier& classifier) {
    _classifier = WeaponClassifier( classifier );
}

void Weapon::set_params(const IParams& params) {
    _params = Params( params );
}

void Weapon::set_requirements(const IParams& requirements) {
    _requirements = Params( requirements );
}


void Weapon::broke(float damage) {
    float durability = _params.get_hit_param(EHitParams::_durability);
    _params.set_hit_param(EHitParams::_durability, durability - damage);
}

void Weapon::repair() {
    float max_durability = _params.get_hit_param(EHitParams::_max_durability);
    _params.set_hit_param(EHitParams::_durability, max_durability);
}


void Weapon::print() const {
    _classifier.print();

    std::cout << "params:\n";
    std::cout << "\tdamage     : " << static_cast<int>(_params.get_hit_param(EHitParams::_min_damage));
    std::cout << '-' << static_cast<int>(_params.get_hit_param(EHitParams::_max_damage)) << '\n';
    std::cout << "\tatk speed  : " << _params.get_hit_param(EHitParams::_atk_speed) << '\n';
    std::cout << "\tdurability : " << static_cast<int>(_params.get_hit_param(EHitParams::_durability));
    std::cout << '(' << static_cast<int>(_params.get_hit_param(EHitParams::_max_durability)) << ")\n";
    std::cout << "\tweight     : " << _params.get_move_param(EMoveParams::_weight) << "\n\n";
    
    std::cout << "requirements:\n";
    std::cout << "\tlevel    : " << static_cast<int>(_requirements.get_exp_param(EExpParams::_level)) << '\n';
    std::cout << "\tstrength : " << static_cast<int>(_requirements.get_main_param(EMainParams::_strength)) << '\n';
    std::cout << "\tstamina  : " << static_cast<int>(_requirements.get_main_param(EMainParams::_stamina)) << '\n';
    std::cout << "\tagility  : " << static_cast<int>(_requirements.get_main_param(EMainParams::_agility)) << '\n';
    std::cout << "\tmind     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_mind)) << '\n';
    std::cout << "\twill     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_will)) << '\n';
    std::cout << "\tluck     : " << static_cast<int>(_requirements.get_main_param(EMainParams::_luck)) << "\n\n";
}


IItem& Weapon::operator=(const IItem& other) {
    return operator=( static_cast< const Weapon& >(other) );
}

Weapon& Weapon::operator=(const Weapon& other) {
    _classifier = other._classifier;
    _params = other._params;
    _requirements = other._requirements;
    return *this;
}