#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "i_item.hpp"
#include "weapon_classifier.hpp"
#include "params.hpp"


class Weapon : public IItem {
public:
    Weapon() { }
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

    void print() const override;

    IItem& operator=(const IItem&) override;
    Weapon& operator=(const Weapon&);

private:
    WeaponClassifier _classifier;
    Params _params;
    Params _requirements;
};


#endif // WEAPON_HPP
