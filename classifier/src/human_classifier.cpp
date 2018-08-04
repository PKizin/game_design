#include "human_classifier.h"


HumanClassifier::HumanClassifier() :
    IClassifier(),
    _class( ECreatureClass::_human ),
    _type( EHumanType::_none )
{ }


int HumanClassifier::get_class() const {
    return static_cast<int>(_class);
}

int HumanClassifier::get_type() const {
    return static_cast<int>(_type);
}


void HumanClassifier::set_type(int val) {
    _type = static_cast< EHumanType >(val);
}

