#ifndef I_FACTORY_HPP
#define I_FACTORY_HPP

#include "i_classifier_factory.hpp"
#include "i_params_factory.hpp"
#include "i_creature_factory.hpp"
#include "i_item_factory.hpp"
#include "i_obstacle_factory.hpp"


class IFactory : public IClassifierFactory, public IParamsFactory, public ICreatureFactory, public IItemFactory, public IObstacleFactory {
public:
    virtual void build_classifier(IClassifier&) const { }
    virtual void build_params(const IClassifier&, IParams&) const { }
    virtual void build_creature(/* ICreature& */) const { }
    virtual void build_item(IItem&) const { }
    virtual void build_obstacle(/* IObstacle& */) const { }

protected:
    IFactory() { }
    virtual ~IFactory() { }
};


#endif // I_FACTORY_HPP
