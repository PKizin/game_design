#include "monster_classifier.h"


MonsterClassifier::MonsterClassifier() :
    IClassifier(),
    _class( ECreatureClass::_monster ),
    _type( EMonsterType::_none )
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
    _type = static_cast< EMonsterType >(type);
}


MonsterClassifier& MonsterClassifier::operator=(const MonsterClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
