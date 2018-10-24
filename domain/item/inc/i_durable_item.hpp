#ifndef I_DURABLE_ITEM_HPP
#define I_DURABLE_ITEM_HPP


class IDurableItem {
public:
    virtual void broke(float) = 0;
    virtual void repair() = 0;

protected:
    IDurableItem() { }
    virtual ~IDurableItem() { }
};


#endif // I_DURABLE_ITEM_HPP
