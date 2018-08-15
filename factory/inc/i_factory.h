#ifndef I_FACTORY_H
#define I_FACTORY_H

#include "i_classifier_factory.h"
#include "i_params_factory.h"
#include "i_creature_factory.h"
#include "i_item_factory.h"
#include "i_obstacle_factory.h"


class IFactory : public IClassifierFactory, public IParamsFactory, public ICreatureFactory, public IItemFactory, public IObstacleFactory {
public:
    virtual void build_classifier(IClassifier&) { }
    virtual void build_params(IParams&) { }
    virtual void build_creature(/* ICreature& */) { }
    virtual void build_item(IItem&) { }
    virtual void build_obstacle(IItem&) { }

protected:
    IFactory() { }
    virtual ~IFactory() { }
};


#endif // I_FACTORY
