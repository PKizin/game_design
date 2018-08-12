#include "weapon.h"


Weapon::Weapon(const IClassifier& classifier, const IParams& params, const IParams& requirements) : 
    IItem()
{
    set_classifier(classifier);
    set_params(params);
    set_requirements(requirements);
}


IClassifier Weapon::get_classifier() const {
    return _classifier;
}

IParams Weapon::get_params() const {
    return _params;
}

IParams Weapon::get_requirements() const {
    return _requirements;
}


void Weapon::set_classifier(const IClassifier& classifier) {
    auto& cla = dynamic_cast< WeaponClassifier& >(const_cast< IClassifier& >(classifier));
    _classifier = cla;
}

void Weapon::set_params(const IParams& params) {
    auto& par = dynamic_cast< Params& >(const_cast< IParams& >(params));
    _params = par;
}

void Weapon::set_requirements(const IParams& requirements) {
    auto& req = dynamic_cast< Params& >(const_cast< IParams& >(requirements));
    _requirements = req;
}


void Weapon::broke(float damage) {
    float durability = _params.get_hit_param(EHitParams::_durability);
    _params.set_hit_param(EHitParams::_durability, durability - damage);
}

void Weapon::repair() {
    float max_durability = _params.get_hit_param(EHitParams::_max_durability);
    _params.set_hit_param(EHitParams::_durability, max_durability);
}

