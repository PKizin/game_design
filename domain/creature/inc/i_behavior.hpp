#ifndef I_BEHAVIOR_HPP
#define I_BEHAVIOR_HPP

class IMoveStrategy;
class IHitStrategy;
class ISearchStrategy;


class IBehavior {
public:
    virtual void get_move_strategy(IMoveStrategy&) const = 0;
    virtual void set_move_strategy(const IMoveStrategy&) = 0;

    virtual void get_hit_strategy(IHitStrategy&) const = 0;
    virtual void set_hit_strategy(const IHitStrategy&) = 0;

    virtual void get_search_strategy(ISearchStrategy&) const = 0;
    virtual void set_search_strategy(const ISearchStrategy&) = 0;

protected:
    IBehavior() { }
    virtual ~IBehavior() { }

};


#endif // I_BEHAVIOR_HPP