#ifndef I_ITEM_HPP
#define I_ITEM_HPP

#include "i_object.hpp"
#include "i_durable_item.hpp"


class IItem : public IObject, public IDurableItem {
public:
    virtual void get_classifier(IClassifier&) const = 0;
    virtual void get_params(IParams&) const = 0;
    virtual void get_requirements(IParams&) const = 0;

    virtual void set_classifier(const IClassifier&) = 0;
    virtual void set_params(const IParams&) = 0;
    virtual void set_requirements(const IParams&) = 0;

    virtual void broke(float) = 0;
    virtual void repair() = 0;

    virtual void print() const = 0;
    
    virtual IItem& operator=(const IItem&) { return *this; }

protected:
    IItem() { }
    virtual ~IItem() { }

private:
    IItem(const IItem&);
};


#endif // I_ITEM_HPP
