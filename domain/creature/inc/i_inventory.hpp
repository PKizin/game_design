#ifndef I_INVENTORY_HPP
#define I_INVENTORY_HPP

class IItemContainer;

class IInventory {
public:
    virtual void get_body(IItemContainer&) const = 0;
    virtual void get_inventory(IItemContainer&) const = 0;
    virtual void set_body(const IItemContainer&) = 0;
    virtual void set_inventory(const IItemContainer&) = 0;

protected:
    IInventory() { }
    virtual ~IInventory() { }
};


#endif // I_INVENTORY_HPP
