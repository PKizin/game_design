#include "rock_classifier.h"


RockClassifier::RockClassifier() :
    IClassifier(),
    _class( EObstacleClass::_rock ),
    _type( ERockType::_none )
{ }


int RockClassifier::get_class() const {
    return static_cast<int>(_class);
}

int RockClassifier::get_type() const {
    return static_cast<int>(_type);
}


void RockClassifier::set_type(int type) {
    _type = static_cast< ERockType >(type);
}

