#ifndef E_BODY_CONTAINERS_HPP
#define E_BODY_CONTAINERS_HPP

#include "e_item_categories.hpp"


struct SBodyWeapons {
    enum EBodyWeapons {
        _NONE,
        _left_hand,
        _right_hand,
        _MAX
    };
};

struct SBodyActiveSlots {
    enum EBodyActiveSlots {
        _NONE,
        _slot1,
        _slot2,
        _slot3,
        _MAX
    };
};


typedef SBodyWeapons::EBodyWeapons          BodyWeapons;
typedef SArmorType::EArmorType              BodyArmory;
typedef SJewerlyType::EJewerlyType          BodyJewerly;
typedef SBodyActiveSlots::EBodyActiveSlots  BodyActiveSlots;


#endif // E_BODY_CONTAINERS_HPP
