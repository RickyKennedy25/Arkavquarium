#include <iostream>
#include "Food.hpp"

const std::string Food::assetPath = "assets/img/food.png";

/**
 * Construct Food at destined position
 * @param {double} absis of food
 * @param {double} ordinate of food
 */
Food::Food(double x, double y) {
    this->position = new Position(x, y, false);
}

/**
 * Move Food to bottom
 * @param {int} minimum height
 * @param {double} elapsedSeconds
 */
void Food::move(int y, double elapsedSeconds) {
    Position *bottom = new Position(0, y, false);
    this->position->moveVertical(*bottom, elapsedSeconds * MAX_VELOCITY);
}

/**
 * @return {Position*} Food Position 
 **/
Position* Food::getPosition() const {
    return this->position;
}

/**
 * @return {std::string} asset path
 */
std::string Food::getAssetPath() {
    return Food::assetPath;
}
