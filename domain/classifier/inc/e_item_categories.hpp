#ifndef E_ITEM_CATEGORIES_HPP
#define E_ITEM_CATEGORIES_HPP

#include <string>


struct SItemClass {
    enum EItemClass {
        _NONE,
        _weapon,
        _armor,
        _jewerly,
        _potion,
        _MAX
    };
};

struct SWeaponType {
    enum EWeaponType {
        _NONE,
        _stick,
        _dagger,
        _sword,
        _staff,
        _MAX
    };
};

struct SWeaponMaterial {
    enum EWeaponMaterial {
        _NONE,
        _wood,
        _steel,
        _glass,
        _MAX
    };
};

struct SWeaponProperty1 {
    enum EWeaponProperty1 {
        _NONE,
        _one_handed,
        _two_handed,
        _MAX
    };
};

struct SArmorType {
    enum EArmorType {
        _NONE,
        _head,
        _shoulders,
        _chest,
        _hands,
        _belt,
        _legs,
        _feet,
        _MAX
    };
};

struct SArmorMaterial {
    enum EArmorMaterial {
        _NONE,
        _rags,
        _cotton,
        _mail,
        _leather,
        _MAX
    };
};

struct SJewerlyType {
    enum EJewerlyType {
        _NONE,
        _neck,
        _finger,
        _MAX
    };
};

struct SJewerlyMaterial {
    enum EJewerlyMaterial {
        _NONE,
        _glass,
        _silver,
        _gold,
        _MAX
    };
};

struct SPotionType {
    enum EPotionType {
        _NONE,
        _hp,
        _mp,
        _exp,
        _MAX
    };
};

struct SPotionProperty1 {
    enum EPotionProperty1 {
        _NONE,
        _small,
        _medium,
        _big,
        _MAX
    };
};


typedef SItemClass::EItemClass              ItemClass;
typedef SWeaponType::EWeaponType            WeaponType;
typedef SWeaponMaterial::EWeaponMaterial    WeaponMaterial;
typedef SWeaponProperty1::EWeaponProperty1  WeaponProperty1;
typedef SArmorType::EArmorType              ArmorType;
typedef SArmorMaterial::EArmorMaterial      ArmorMaterial;
typedef SJewerlyType::EJewerlyType          JewerlyType;
typedef SJewerlyMaterial::EJewerlyMaterial  JewerlyMaterial;
typedef SPotionType::EPotionType            PotionType;
typedef SPotionProperty1::EPotionProperty1  PotionProperty1;


#endif // E_ITEM_CATEGORIES_HPP
