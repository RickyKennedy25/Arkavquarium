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
	this->status = Status::STATUS_IDLE;
    	this->position = new Position(maxWidth, maxHeight, true);
	this->destination = new Position(maxWidth, maxHeight, true);
	this->growthStep = GrowthStep::GROWTH_STEP_ONE;
	this->starvingTimer = 0;
	this->orientation = (this->destination->getAbsis() > this->position->getAbsis()) ? Orientation::ORIENTATION_RIGHT : Orientation::ORIENTATION_LEFT;
	this->eatCounter = 0;
}

/**
 * Getter  
 */
int Fish::getStatus() const {
    return this->status;
}

Position* Fish::getPosition() const {
    return this->position;
}

Position* Fish::getDestination() const {
    return this->destination;
}

int Fish::getGrowthStep() const {
    return this->growthStep;
}

int Fish::getStarvingTimer() const {
    return this->starvingTimer;
}

int Fish::getOrientation() const {
    return this->orientation;
}

int Fish::getEatCounter() const {
    return this->eatCounter;
}

/**
 * Setter
 */
void Fish::setStatus(int status) {
    this->status = status;
}

void Fish::setPosition(Position* position) {
    this->position = position;
}

void Fish::setDestination(Position* position) {
    this->destination = position;
}

void Fish::setGrowthStep(int growthStep) {
    this->growthStep = growthStep;
}

void Fish::setStarvingTimer(int starvingTimer) {
    this->starvingTimer = starvingTimer;
}

void Fish::setOrientation(int orientation) {
    this->orientation = orientation;
}

/**
 * @return {bool} REPLETE TIME <= starvingTimer <= STARVING TIME 
 */
bool Fish::isStarving() {
    return (REPLETE_TIME <= this->starvingTimer) && (this->starvingTimer <= STARVATION_TIME);
}

/**
 * Increment eatCounter
 * If exceed minimum eatCounter, upgrade growthStep to next step
 */
void Fish::eat() {
    this->eatCounter++;
	if(this->eatCounter == FIRST_GROWTH_EAT_COUNTER)
			this->growthStep = GrowthStep::GROWTH_STEP_TWO;
	else if(this->eatCounter == SECOND_GROWTH_EAT_COUNTER)
			this->growthStep = GrowthStep::GROWTH_STEP_THREE;
}


/**
 * Move Fish to the dest
 * @param {Position} is the nearest Food for Guppy
 *   or nearest Guppy for Piranha
 */
void Fish::moveToDestination(Position* position) {
	this->position->move(*position, MAX_VELOCITY); 
}

/**
 * Move Fish to their default destination
 * If Fish Position equal to default destination
 * random new destination 
 */
void Fish::moveToDestination() {
    if(this->position == this->destination)
	    this->destination = new Position(500, 500, true);
    this->position->move(*this->destination, MAX_VELOCITY);
}
