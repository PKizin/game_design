#ifndef I_SEARCH_STRATEGY_HPP
#define I_SEARCH_STRATEGY_HPP


class ISearchStrategy {
public:
    virtual void search(ICreature&) = 0;

protected:
    ISearchStrategy();
    virtual ~ISearchStrategy();
};


#endif // I_SEARCH_STRATEGY_HPP
