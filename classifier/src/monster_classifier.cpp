#include "monster_classifier.h"


MonsterClassifier::MonsterClassifier() :
    IClassifier(),
    _class( ECreatureClass::_monster ),
    _type( EMonsterType::_none )
{ }


int MonsterClassifier::get_class() const {
    return static_cast<int>(_class);
}

int MonsterClassifier::get_type() const {
    return static_cast<int>(_type);
}


void MonsterClassifier::set_type(int type) {
    _type = static_cast< EMonsterType >(type);
}

