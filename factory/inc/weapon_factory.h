#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

#include "i_factory.h"


class WeaponFactory : public IFactory {
public:
    WeaponFactory();
    virtual ~WeaponFactory() { }

    void build_classifier(IClassifier&) override;
    void build_params(IParams&) override;
    void build_item(IItem&) override;
};


#endif // WEAPON_FACTORY_H
