#ifndef WEAPON_H
#define WEAPON_H

#include "i_item.h"
#include "weapon_classifier.h"
#include "params.h"


class Weapon : public IItem {
public:
    Weapon(const IClassifier&, const IParams&, const IParams&);
    virtual ~Weapon() { }

    void get_classifier(IClassifier&) const override;
    void get_params(IParams&) const override;
    void get_requirements(IParams&) const override;

    void set_classifier(const IClassifier&) override;
    void set_params(const IParams&) override;
    void set_requirements(const IParams&) override;

    void broke(float) override;
    void repair() override;

private:
    Weapon();

    WeaponClassifier _classifier;
    Params _params;
    Params _requirements;
};


#endif // WEAPON_H
