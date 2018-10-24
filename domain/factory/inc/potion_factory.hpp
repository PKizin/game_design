#ifndef POTION_FACTORY_HPP
#define POTION_FACTORY_HPP

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

    void build_params_hp(PotionProperty1, IParams&) const;
    void build_params_mp(PotionProperty1, IParams&) const;
    void build_params_exp(PotionProperty1, IParams&) const;

    float coeff_property1(PotionProperty1) const;

    void correct_params(IParams&) const;
    void correct_requirements(IParams&) const;
};


#endif // POTION_FACTORY_HPP
