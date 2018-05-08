//
// Created by Scott Wickersham on 5/5/18.
//

#include "Doodlebug.hpp"


Doodlebug::Doodlebug() : Critter() {

}

Doodlebug::Doodlebug(Grid *grid, int currentRow, int currentCol) : Critter(grid, currentRow, currentCol) {
    stepsSurvived = 0;


}

void Doodlebug::breed() {
    Critter::breed();
}
