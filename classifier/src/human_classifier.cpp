#include "human_classifier.h"


HumanClassifier::HumanClassifier() :
    IClassifier(),
    _class( CreatureClass::_human ),
    _type( HumanType::_NONE )
{
}

HumanClassifier::HumanClassifier(const HumanClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type )
{
}


int HumanClassifier::get_class() const {
    return static_cast<int>(_class);
}

int HumanClassifier::get_type() const {
    return static_cast<int>(_type);
}


void HumanClassifier::set_type(int val) {
    _type = static_cast< HumanType >(val);
}


HumanClassifier& HumanClassifier::operator=(const HumanClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
