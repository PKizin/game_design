#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

#include "i_factory.hpp"
#include "e_item_categories.hpp"


class WeaponFactory : public IFactory {
public:
    WeaponFactory() { }
    virtual ~WeaponFactory() { }

    void build_item(IItem&) const override;

private:
    void build_classifier(IClassifier&) const override;
    void build_params(const IClassifier&, IParams&) const override;

    void build_params_stick(float level, WeaponMaterial, WeaponProperty1, IParams&) const;
    void build_params_dagger(float level, WeaponMaterial, WeaponProperty1, IParams&) const;
    void build_params_sword(float level, WeaponMaterial, WeaponProperty1, IParams&) const;
    void build_params_staff(float level, WeaponMaterial, WeaponProperty1, IParams&) const;

    float coeff_material(WeaponMaterial) const;
    float coeff_property1(WeaponProperty1) const;

    void correct_params(IParams&) const;
    void correct_requirements(IParams&) const;
};


#endif // WEAPON_FACTORY_H
