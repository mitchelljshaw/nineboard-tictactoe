// =============================================================================
// COORDINATE.H - Coordinate Structure Definition
// =============================================================================
// Represents a coordinate pair for board positioning
// Stores x,y coordinates for tracking current board position

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Coordinate {    // Player X and Y co-ordinates stored together
int x; // X-coordinate (0-2)
int y; // Y-coordinate (0-2)
};

#endif /* COORDINATE_H_ */
