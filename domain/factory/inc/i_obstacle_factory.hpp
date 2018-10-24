#ifndef I_OBSTACLE_FACTORY_HPP
#define I_OBSTACLE_FACTORY_HPP


class IObstacleFactory {
public:
    virtual void build_obstacle(/* IObstacle& */) const = 0;

protected:
    IObstacleFactory() { }
    virtual ~IObstacleFactory() { }
};


#endif // I_OBSTACLE_FACTORY_HPP
