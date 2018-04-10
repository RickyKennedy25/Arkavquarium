#include <iostream>
#include "Food.hpp"

const std::string Food::assetPath = "assets/img/food.png";
/**
 * Construct Food at random position and 0 ordinate
 */
Food::Food(int maxWidth, int maxHeight) {
    this->position = new Position(maxWidth, maxHeight, true); // assume maxHeight = 600 and maxWidth = 800 
    this->position->setOrdinate(0);
}

/**
 * Construct Food at x,0
 * @param {int} absis position
 */
Food::Food(int x) {
    this->position = new Position(x, 0);
}

/**
 * Move Food to bottom
 * @param {double} elapsedSeconds
 */
void Food::move(double elapsedSeconds) {
    Position *bottom = new Position(0, 0, false);
    this->position->moveVertical(*bottom, elapsedSeconds * MAX_VELOCITY);
}

/**
 * @return {Position*} Food Position 
 **/
Position* Food::getPosition() {
    return this->position;
}

/**
 * @return {std::string} asset path
 */
std::string Food::getAssetPath() {
    return Food::assetPath;
}
