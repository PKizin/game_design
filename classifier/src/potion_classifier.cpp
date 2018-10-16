#include "potion_classifier.hpp"


PotionClassifier::PotionClassifier() :
    IClassifier(),
    _class( ItemClass::_potion ),
    _type( PotionType::_NONE ),
    _property1( PotionProperty1::_NONE )
{
}

PotionClassifier::PotionClassifier(PotionType type, PotionProperty1 prop1) :
    IClassifier(),
    _class( ItemClass::_potion ),
    _type( type ),
    _property1( prop1 )
{
}

PotionClassifier::PotionClassifier(const PotionClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type ),
    _property1( other._property1 )
{
}

PotionClassifier::PotionClassifier(const IClassifier& other) :
    PotionClassifier( static_cast< const PotionClassifier& >(other) )
{
}


int PotionClassifier::get_class() const {
    return static_cast<int>(_class);
}

int PotionClassifier::get_type() const {
    return static_cast<int>(_type);
}

int PotionClassifier::get_property1() const {
    return static_cast<int>(_property1);
}


void PotionClassifier::set_type(int type) {
    _type = static_cast< PotionType >(type);
}

void PotionClassifier::set_property1(int property1) {
    _property1 = static_cast< PotionProperty1 >(property1);
}


IClassifier& PotionClassifier::operator=(const IClassifier& other) {
    return operator=( static_cast< const PotionClassifier& >(other) );
}

PotionClassifier& PotionClassifier::operator=(const PotionClassifier& other) {
    _class = other._class;
    _type = other._type;
    _property1 = other._property1;
    return *this;
}
