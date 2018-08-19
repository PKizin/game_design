#ifndef ARMOR_FACTORY_H
#define ARMOR_FACTORY_H

#include "i_factory.h"


class ArmorFactory : public IFactory {
public:
    ArmorFactory() { }
    virtual ~ArmorFactory() { }

    void build_classifier(IClassifier&) const override;
    void build_params(IParams&) const override;
    void build_item(IItem&) const override;

private:
    void correct_params(IParams&) const;
    void correct_requirements(IParams&) const;
};


#endif // ARMOR_FACTORY_H
