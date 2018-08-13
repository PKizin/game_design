#ifndef WEAPON_H
#define WEAPON_H

#include "i_item.h"
#include "weapon_classifier.h"
#include "params.h"


class Weapon : public IItem {
public:
    Weapon(const IClassifier&, const IParams&, const IParams&);
    virtual ~Weapon() { }

    void get_classifier(const IClassifier&) const override;
    void get_params(const IParams&) const override;
    void get_requirements(const IParams&) const override;

    void set_classifier(const IClassifier&) override;
    void set_params(const IParams&) override;
    void set_requirements(const IParams&) override;

    void broke(float) override;
    void repair() override;

private:
    Weapon();

    const IClassifier& _classifier;
    const IParams& _params;
    const IParams& _requirements;
};


#endif // WEAPON_H
