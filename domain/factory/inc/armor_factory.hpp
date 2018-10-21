#ifndef ARMOR_FACTORY_H
#define ARMOR_FACTORY_H

#include "i_factory.hpp"
#include "e_item_categories.hpp"


class ArmorFactory : public IFactory {
public:
    ArmorFactory() { }
    virtual ~ArmorFactory() { }

    void build_item(IItem&) const override;

private:
    void build_classifier(IClassifier&) const override;
    void build_params(const IClassifier&, IParams&) const override;

    void build_params_head(float level, ArmorMaterial, IParams&) const;
    void build_params_shoulders(float level, ArmorMaterial, IParams&) const;
    void build_params_chest(float level, ArmorMaterial, IParams&) const;
    void build_params_hands(float level, ArmorMaterial, IParams&) const;
    void build_params_belt(float level, ArmorMaterial, IParams&) const;
    void build_params_legs(float level, ArmorMaterial, IParams&) const;
    void build_params_feet(float level, ArmorMaterial, IParams&) const;

    float coeff_material(ArmorMaterial) const;

    void correct_params(IParams&) const;
    void correct_requirements(IParams&) const;
};


#endif // ARMOR_FACTORY_H
