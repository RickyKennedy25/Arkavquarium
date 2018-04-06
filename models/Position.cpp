#include "Position.hpp"

/**
 * Construct Position with random x and y
 */
Position::Position() {
    //
}

/**
 * Construct Position with x and y
 * @param {int} absis of Position
 * @param {int} ordinate of Position
 */
Position::Position(int x, int y) {
    //
}


/**
 * @return {int} absis of the position
 */
int Position::getAbsis() const {
    return 0;
}

/**
 * @return {int} ordinate of the position
 */
int Position::getOrdinate() const {
    return 0;
}

/**
 * set absis of the position
 * @param {int} absis of Position
 */
void Position::setAbsis(int x) {
    //
}

/**
 * set ordinate of the position
 * @param {int} ordinate of Position
 */
void Position::setOrdinate(int y) {
    //
}

/**
 * Set x and y to random
 */
void Position::random() {
    //
}

/**
 * Set x and y to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::move(Position dest, int maxVelocity) {
    //
}

/**
 * Set x to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::moveHorizontal(Position dest, int maxVelocity) {
    //
}

/**
 * Set y to nearest coordinate with dest
 * but no more than pythagorean distance maxVelocity
 */
void Position::moveVertical(Position dest,int maxVelocity) {
    //
}