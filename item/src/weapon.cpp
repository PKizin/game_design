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

