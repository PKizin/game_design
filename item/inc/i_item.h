#ifndef I_ITEM_H
#define I_ITEM_H

#include "i_object.h"
#include "i_durable_item.h"


class IItem : public IObject, public IDurableItem {
public:
    virtual ~IItem() { }

    virtual void get_classifier(const IClassifier&) const = 0;
    virtual void get_params(const IParams&) const = 0;
    virtual void get_requirements(const IParams&) const = 0;

    virtual void set_classifier(const IClassifier&) = 0;
    virtual void set_params(const IParams&) = 0;
    virtual void set_requirements(const IParams&) = 0;

    virtual void broke(float) = 0;
    virtual void repair() = 0;

protected:
    IItem() : IObject(), IDurableItem() { }

private:
    IItem(const IItem&);
    IItem& operator=(const IItem&);
};


#endif // I_ITEM_H
