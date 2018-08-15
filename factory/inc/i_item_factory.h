#ifndef I_ITEM_FACTORY_H
#define I_ITEM_FACTORY_H

#include "i_item.h"


class IItemFactory {
public:
    virtual void build_item(IItem&) = 0;

protected:
    IItemFactory() { }
    virtual ~IItemFactory() { }
};


#endif // I_ITEM_FACTORY_H
