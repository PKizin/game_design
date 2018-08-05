#ifndef E_ITEM_CATEGORIES_H
#define E_ITEM_CATEGORIES_H


enum class EItemClass {
    _none,
    _weapon,
    _armor,
    _jewerly,
    _potion
};


enum class EWeaponType {
    _none,
    _stick,
    _dagger,
    _sword,
    _staff
};

enum class EWeaponMaterial {
    _none,
    _wood,
    _steel,
    _glass
};

enum class EWeaponProperty1 {
    _none,
    _one_handed,
    _two_handed
};


enum class EArmorType {
    _none,
    _head,
    _shoulders,
    _chest,
    _hands,
    _belt,
    _legs,
    _feet
};

enum class EArmorMaterial {
    _none,
    _rags,
    _cotton,
    _mail,
    _leather
};


enum class EJewerlyType {
    _none,
    _neck,
    _finger
};

enum class EJewerlyMaterial {
    _none,
    _glass,
    _silver,
    _gold
};


enum class EPotionType {
    _none,
    _hp,
    _mp,
    _exp
};

enum class EPotionProperty1 {
    _none,
    _small,
    _medium,
    _big
};


#endif // E_ITEM_CATEGORIES_H
