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
	this->status = idle;
    this->position = new Position(maxWidth, maxHeight, true);
	this->destination = new Position(maxWidth, maxHeight, true);
	this->growthStep = stepOne;
	this->starvingTimer = 0;
	this->orientation =
        (this->destination->getAbsis() > this->position->getAbsis()) ?
            right : left;
	this->eatCounter = 0;
}

/**
 * Getter  
 */
tStatus Fish::getStatus() const {
    return this->status;
}

Position* Fish::getPosition() const {
    return this->position;
}

Position* Fish::getDestination() const {
    return this->destination;
}

tGrowthStep Fish::getGrowthStep() const {
    return this->growthStep;
}

int Fish::getStarvingTimer() const {
    return this->starvingTimer;
}

tOrientation Fish::getOrientation() const {
    return this->orientation;
}

int Fish::getEatCounter() const {
    return this->eatCounter;
}

/**
 * Setter
 */
void Fish::setStatus(tStatus status) {
    this->status = status;
}

void Fish::setPosition(Position* position) {
    this->position = position;
}

void Fish::setDestination(Position* position) {
    this->destination = position;
}

void Fish::setGrowthStep(tGrowthStep growthStep) {
    this->growthStep = growthStep;
}

void Fish::setStarvingTimer(int starvingTimer) {
    this->starvingTimer = starvingTimer;
}

void Fish::setOrientation(tOrientation orientation) {
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
	if (this->eatCounter == FIRST_GROWTH_EAT_COUNTER)
		this->growthStep = stepTwo;
	else if(this->eatCounter == SECOND_GROWTH_EAT_COUNTER)
		this->growthStep = stepThree;
}


/**
 * Move Fish to the dest
 * @param {Position} is the nearest Food for Guppy
 *   or nearest Guppy for Piranha
 */
void Fish::moveToDestination(Position* position, double elapsedSeconds) {
	this->position->move(*position, elapsedSeconds * MAX_VELOCITY); 
}

/**
 * Move Fish to their default destination
 * If Fish Position equal to default destination
 * random new destination 
 */
void Fish::moveToDestination(int maxWidth, int maxHeight, double elapsedSeconds) {
    if (*(this->position) == *(this->destination)){
	    this->destination = new Position(maxWidth, maxHeight, true);
        std::cout<<this->destination->getAbsis()<<","
                 <<this->destination->getOrdinate()<<std::endl;
    }
    this->position->move(*(this->destination), elapsedSeconds * MAX_VELOCITY);
}