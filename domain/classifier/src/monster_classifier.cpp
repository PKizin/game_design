#include "monster_classifier.hpp"


MonsterClassifier::MonsterClassifier() :
    IClassifier(),
    _class( CreatureClass::_monster ),
    _type( MonsterType::_NONE )
{
}

MonsterClassifier::MonsterClassifier(const MonsterClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type )
{
}


int MonsterClassifier::get_class() const {
    return static_cast<int>(_class);
}

int MonsterClassifier::get_type() const {
    return static_cast<int>(_type);
}


void MonsterClassifier::set_type(int type) {
    _type = static_cast< MonsterType >(type);
}


MonsterClassifier& MonsterClassifier::operator=(const MonsterClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
