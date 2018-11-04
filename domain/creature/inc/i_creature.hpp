#ifndef I_CREATURE_HPP
#define I_CREATURE_HPP


class ICreature : public IAction, public IObject, public IBehavior, public IInventory {
public:
    virtual void move() = 0;
    virtual void hit() = 0;
    virtual void loot() = 0;
    virtual void use() = 0;

    virtual void set_target(const ICreature&) = 0;
    virtual bool search(ICreature&) = 0;
    virtual void set_use_item(const IItem&) = 0;

    virtual void get_classifier(IClassifier&) const = 0;
    virtual void get_params(IParams&) const = 0;
    virtual void set_classifier(const IClassifier&) = 0;
    virtual void set_params(const IParams&) = 0;

    virtual void get_move_strategy(IMoveStrategy&) const = 0;
    virtual void get_hit_strategy(IHitStrategy&) const = 0;
    virtual void set_move_strategy(const IMoveStrategy&) = 0;
    virtual void set_hit_strategy(const IHitStrategy&) = 0;

    virtual void get_body(IItemContainer&) const = 0;
    virtual void get_inventory(IItemContainer&) const = 0;
    virtual void set_body(const IItemContainer&) = 0;
    virtual void set_inventory(const IItemContainer&) = 0;

protected:
    ICreature() { }
    ICreature(const ICreature&) { }
    virtual ~ICreature() { }

    ICreature& operator=(const ICreature&) { }
    ICreature& operator=(const ICreature&) const { }
};


#endif // I_CREATURE_HPP
