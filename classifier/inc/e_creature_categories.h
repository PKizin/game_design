#ifndef E_CREATURE_CATEGORIES_H
#define E_CREATURE_CATEGORIES_H


struct SCreatureClass {
    enum ECreatureClass {
        _NONE,
        _human,
        _monster,
        _MAX
    };
};

struct SHumanType {
    enum EHumanType {
        _NONE,
        _player,
        _npc,
        _MAX
    };
};

struct SMonsterType {
    enum EMonsterType {
        _NONE,
        _dog,
        _bat,
        _vampire,
        _MAX
    };
};


typedef SCreatureClass::ECreatureClass  CreatureClass;
typedef SHumanType::EHumanType          HumanType;
typedef SMonsterType::EMonsterType      MonsterType;


#endif // E_CREATURE_CATEGORIES_H
