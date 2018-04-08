#include <iostream>
#include "Snail.hpp"

/**
 * Construct Snail with random position
 */
Snail::Snail() {
   this->position = new Position(500, 500, true);
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
