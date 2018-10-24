#ifndef E_OBSTACLE_CATEGORIES_HPP
#define E_OBSTACLE_CATEGORIES_HPP


struct SObstacleClass {
    enum EObstacleClass {
        _NONE,
        _terrain,
        _rock,
        _tree,
        _MAX
    };
};

struct STerrainType {
    enum ETerrainType {
        _NONE,
        _green,
        _mud,
        _snow,
        _water,
        _MAX
    };
};

struct SRockType {
    enum ERockType {
        _NONE,
        _top_left,
        _top_right,
        _bottom_left,
        _bottom_right,
        _horizontal,
        _vertical,
        _middle,
        _MAX
    };
};

struct STreeType {
    enum ETreeType {
        _NONE,
        _oak,
        _pine,
        _aspen,
        _MAX
    };
};


typedef SObstacleClass::EObstacleClass ObstacleClass;
typedef STerrainType::ETerrainType TerrainType;
typedef SRockType::ERockType RockType;
typedef STreeType::ETreeType TreeType;


#endif // E_OBSTACLE_CATEGORIES_HPP
