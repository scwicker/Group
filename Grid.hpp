//
// Created by Scott Wickersham on 5/5/18.
//

#ifndef GROUPPROJECT_GRID_HPP
#define GROUPPROJECT_GRID_HPP


#include "Critter.hpp"

class Grid {
private:
    Critter*** grid;
public:
    Grid();
    ~Grid();

    long Print();
};


#endif //GROUPPROJECT_GRID_HPP
