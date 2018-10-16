#include "potion.hpp"
#include <vector>


Potion::Potion(const IClassifier& classifier, const IParams& params, const IParams& requirements) :
    IItem(),
    _classifier( classifier ),
    _params( params ),
    _requirements( requirements )
{
}


void Potion::get_classifier(IClassifier& classifier) const {
    classifier = PotionClassifier( _classifier );
}

void Potion::get_params(IParams& params) const {
    params = Params( _params );
}

void Potion::get_requirements(IParams& requirements) const {
    requirements = Params( _requirements );
}


void Potion::set_classifier(const IClassifier& classifier) {
    _classifier = PotionClassifier( classifier );
}

void Potion::set_params(const IParams& params) {
    _params = Params( params );
}

void Potion::set_requirements(const IParams& requirements) {
    _requirements = Params( requirements );
}


void Potion::broke(float damage)
{
}

void Potion::repair()
{
}


void Potion::print() const
{
}


IItem& Potion::operator=(const IItem& other) {
    return operator=( static_cast< const Potion& >(other) );
}

Potion& Potion::operator=(const Potion& other) {
    _classifier = other._classifier;
    _params = other._params;
    _requirements = other._requirements;
    return *this;
}