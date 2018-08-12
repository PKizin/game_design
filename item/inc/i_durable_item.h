#ifndef I_DURABLE_ITEM_H
#define I_DURABLE_ITEM_H


class IDurableItem {
public:
    virtual ~IDurableItem() { }

    virtual void broke(float) = 0;
    virtual void repair() = 0;

protected:
    IDurableItem() { }
};


#endif // I_DURABLE_ITEM_H
