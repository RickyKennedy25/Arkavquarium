#include <iostream>
#include "Fish.hpp"

/**
 * Construct Fish
 * Set status to STATUS_IDLE
 * Set position to random new position
 * Set destination to random new position
 * Set growthStep to GROWTH_STEP_ONE
 * Set starvingTimer to zero
 * Set orientation according to destination
 * Set eatCounter to zero
 */
Fish::Fish(int maxWidth, int maxHeight) {
    this->position = new Position(maxWidth, maxHeight, true);
}

/**
 * Getter  
 */
Status Fish::getStatus() const {
    return 0;
}

Position* Fish::getPosition() const {
    return this->position;
}

Position* Fish::getDestination() const {
    return NULL;
}

GrowthStep Fish::getGrowthStep() const {
    return 0;
}

int Fish::getStarvingTimer() const {
    return 0;
}

Orientation Fish::getOrientation() const {
    return 0;
}

int Fish::getEatCounter() const {
    return 0;
}

/**
 * Setter
 */
void Fish::setStatus(Status status) {
    //
}

void Fish::setPosition(Position* position) {
    //
}

void Fish::setDestination(Position* position) {
    //
}

void Fish::setGrowthStep(GrowthStep growthStep) {
    //
}

void Fish::setStarvingTimer(int starvingTimer) {
    //
}

void Fish::setOrientation(Orientation orientation) {
    //
}

/**
 * @return {bool} REPLETE TIME <= starvingTimer <= STARVING TIME 
 */
bool Fish::isStarving() {
    return true;
}

/**
 * Increment eatCounter
 * If exceed minimum eatCounter, upgrade growthStep to next step
 */
void Fish::eat() {
    //
}


/**
 * Move Fish to the dest
 * @param {Position} is the nearest Food for Guppy
 *   or nearest Guppy for Piranha
 */
void Fish::moveToDestination(Position* position) {
    //
}

/**
 * Move Fish to their default destination
 * If Fish Position equal to default destination
 * random new destination 
 */
void Fish::moveToDestination() {
    //
}
