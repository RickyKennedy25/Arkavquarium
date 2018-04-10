#include <iostream>
#include "Snail.hpp"

const std::string Snail::assetPath = "assets/img/snail.png";

/**
 * Construct Snail with random position
 */
Snail::Snail(int maxWidth, int maxHeight) {
   this->position = new Position(maxWidth, maxHeight, true);
   this->position->setOrdinate(maxHeight/10);
}

/**
 * Returns the snail position
 */
Position* Snail::getPosition() const {
    return this->position;
}

/**
 * Move position to dest not exceeding MAX_VELOCITY
 * @param {Position} destination
 */
void Snail::moveToDestination(Position position, double elapsedSeconds) {
    this->position->moveHorizontal(position, elapsedSeconds * MAX_VELOCITY);
}

/**
 * @return {std::string} asset path
 */
std::string Snail::getAssetPath() {
    return Snail::assetPath;
}