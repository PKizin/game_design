#ifndef POTION_FACTORY_H
#define POTION_FACTORY_H

#include "i_factory.hpp"
#include "e_item_categories.hpp"


class PotionFactory : public IFactory {
public:
    PotionFactory() { }
    virtual ~PotionFactory() { }

    void build_item(IItem&) const override;

private:
    void build_classifier(IClassifier&) const override;
    void build_params(const IClassifier&, IParams&) const override;

    void build_params_hp(float level, PotionProperty1, IParams&) const;
    void build_params_mp(float level, PotionProperty1, IParams&) const;
    void build_params_exp(float level, PotionProperty1, IParams&) const;

    float coeff_property1(PotionProperty1) const;

    void correct_params(IParams&) const;
    void correct_requiremets(IParams&) const;
};


#endif // POTION_FACTORY_H
