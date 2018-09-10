#ifndef ARMOR_FACTORY_H
#define ARMOR_FACTORY_H

#include "i_factory.h"


class ArmorFactory : public IFactory {
public:
    ArmorFactory() { }
    virtual ~ArmorFactory() { }

    void build_item(IItem&) const override;

private:
    void build_classifier(IClassifier&) const override;
    void build_params(const IClassifier&, IParams&) const override;

    void correct_params(const IClassifier&, IParams&) const;
    void correct_requirements(const IClassifier&, IParams&) const;
};


#endif // ARMOR_FACTORY_H
