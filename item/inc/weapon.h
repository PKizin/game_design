#ifndef WEAPON_H
#define WEAPON_H

#include "i_item.h"
#include "weapon_classifier.h"
#include "params.h"


class Weapon : public IItem {
public:
    Weapon(const IClassifier&, const IParams&, const IParams&);
    virtual ~Weapon() { }

    IClassifier get_classifier() const override;
    IParams get_params() const override;
    IParams get_requirements() const override;

    void set_classifier(const IClassifier&) override;
    void set_params(const IParams&) override;
    void set_requirements(const IParams&) override;

    void broke(float) override;
    void repair() override;

private:
    Weapon();

    // change it to pointers or references
    const IClassifier& _classifier = WeaponClassifier(;
    IParams _params;
    IParams _requirements;
};


#endif // WEAPON_H
