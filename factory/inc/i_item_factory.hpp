#ifndef I_ITEM_FACTORY_H
#define I_ITEM_FACTORY_H

#include "i_item.hpp"


class IItemFactory {
public:
    virtual void build_item(IItem&) const = 0;

protected:
    IItemFactory() { }
    virtual ~IItemFactory() { }
};


#endif // I_ITEM_FACTORY_H
