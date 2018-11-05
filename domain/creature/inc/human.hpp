#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "i_creature.hpp"


class Human : public ICreature {
public:
    void move() override;
    void hit() override;
    void loot() override;
    void use() override;

    void set_target(const ICreature&) override;
    bool search(ICreature&) override;
    void set_use_item(const IItem&) override;

    void get_classifier(IClassifier&) const override;
    void get_params(IParams&) const override;
    void set_classifier(const IClassifier&) override;
    void set_params(const IParams&) override;

    void get_move_strategy(IMoveStrategy&) const override;
    void get_hit_strategy(IHitStrategy&) const override;
    void set_move_strategy(const IMoveStrategy&) override;
    void set_hit_strategy(const IHitStrategy&) override;

    void get_body(IItemContainer&) const override;
    void get_inventory(IItemContainer&) const override;
    void set_body(const IItemContainer&) override;
    void set_inventory(const IItemContainer&) override;

    Human();
    ~Human();

    Human& operator=(const Human&);
    Human& operator=(const Human&) const;

private:
    


};


#endif // HUMAN_HPP
