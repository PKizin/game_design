#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

#include "i_factory.h"


class WeaponFactory : public IFactory {
public:
    WeaponFactory() { }
    virtual ~WeaponFactory() { }

    void build_classifier(IClassifier&) const override;
    void build_params(IParams&) const override;
    void build_item(IItem&) const override;

private:
    void correct_params(IParams&) const;
    void correct_requirements(IParams&) const;
};


#endif // WEAPON_FACTORY_H
