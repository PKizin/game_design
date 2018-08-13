#include "weapon.h"


Weapon::Weapon(const IClassifier& classifier, const IParams& params, const IParams& requirements) : 
    IItem(),
    _classifier( classifier ),
    _params( params ),
    _requirements( requirements )
{
}


void Weapon::get_classifier(const IClassifier& classifier) const {
    IClassifier::copy< WeaponClassifier >(_classifier, classifier);
}

void Weapon::get_params(const IParams& params) const {
    IParams::copy< Params >(_params, params);
}

void Weapon::get_requirements(const IParams& requirements) const {
    IParams::copy< Params >(_requirements, requirements);
}


void Weapon::set_classifier(const IClassifier& classifier) {
    IClassifier::copy< WeaponClassifier >(classifier, _classifier);
}

void Weapon::set_params(const IParams& params) {
    IParams::copy< Params >(params, _params);
}

void Weapon::set_requirements(const IParams& requirements) {
    IParams::copy< Params >(requirements, _requirements);
}


void Weapon::broke(float damage) {
    IParams& params = const_cast< IParams& >(_params);
    float durability = params.get_hit_param(EHitParams::_durability);
    params.set_hit_param(EHitParams::_durability, durability - damage);
}

void Weapon::repair() {
    IParams& params = const_cast< IParams& >(_params);
    float max_durability = params.get_hit_param(EHitParams::_max_durability);
    params.set_hit_param(EHitParams::_durability, max_durability);
}

