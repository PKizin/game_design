#include "rock_classifier.h"


RockClassifier::RockClassifier() :
    IClassifier(),
    _class( ObstacleClass::_rock ),
    _type( RockType::_NONE )
{
}

RockClassifier::RockClassifier(const RockClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type )
{
}


int RockClassifier::get_class() const {
    return static_cast<int>(_class);
}

int RockClassifier::get_type() const {
    return static_cast<int>(_type);
}


void RockClassifier::set_type(int type) {
    _type = static_cast< RockType >(type);
}


RockClassifier& RockClassifier::operator=(const RockClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
