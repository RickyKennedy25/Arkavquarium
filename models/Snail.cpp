#include <iostream>
#include "Snail.hpp"

/**
 * Construct Snail with random position
 */
Snail::Snail(int maxWidth, int maxHeight) {
   this->position = new Position(maxWidth, maxHeight, true);
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
void Snail::moveToDestination(Position position) {
    this->position->move(position, MAX_VELOCITY);
}
