#ifndef E_OBSTACLE_CATEGORIES
#define E_OBSTACLE_CATEGORIES


enum class EObstacleClass {
    _none,
    _terrain,
    _rock,
    _tree
};


enum class ETerrainType {
    _none,
    _green,
    _mud,
    _snow,
    _water
};

enum class ERockType {
    _none,
    _top_left,
    _top_right,
    _bottom_left,
    _bottom_right,
    _horizontal,
    _vertical,
    _middle
};

enum class ETreeType {
    _none,
    _oak,
    _pine,
    _aspen
};


#endif // E_OBSTACLE_CATEGORIES
