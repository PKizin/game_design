#ifndef I_ACTION_HPP
#define I_ACTION_HPP

class ICreature;
class IItem;

class IAction {
public:
    virtual void move() = 0;
    virtual void hit() = 0;
    virtual void loot() = 0;
    virtual void use() = 0;

    virtual void set_target(const ICreature&) = 0;
    virtual void set_use_item(const IItem&) = 0;

    virtual bool search(ICreature&) = 0;

protected:
    IAction() { }
    virtual ~IAction() { }

};


#endif // I_ACTION_HPP
