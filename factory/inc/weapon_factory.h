#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

#include "i_factory.h"


class WeaponFactory : public IFactory {
public:
    WeaponFactory() { }
    virtual ~WeaponFactory() { }

    void build_item(IItem&) const override;

private:
    void build_classifier(IClassifier&) const override;
    void build_params(const IClassifier&, IParams&) const override;

    void correct_params(const IClassifier&, IParams&) const;
    void correct_requirements(const IClassifier&, IParams&) const;
};


#endif // WEAPON_FACTORY_H
