#include <iostream>
#include "Coin.hpp"

/**
 * Construct Coin at random position and random value
 * assume value less than 10
 */
Coin::Coin() {
    this->position = new Position(600,800,true); //Sementara perlu parameter maxWidth dan parameter maxHeight
    this->value = rand() %10; 
}

/**
 * Construct Coin at position
 * @param {int} value of coin
 * @param {Position} initial position
 */
Coin::Coin(int value, Position position) {
    this->position = new Position(position.getAbsis(), position.getOrdinate() );
    this->value = value;
}

/**
 * Decrease y-position by velocity less than maxVelocity
 */
void Coin::move() {
    Position *dest ;
    double absis = this->position->getAbsis();
    dest = new Position(absis,800); // assume maxHeight 800
    this->position->moveVertical(*dest,(double)MAX_VELOCITY);
}

/**
 * @return {Position*} Coin position
 */
Position* Coin::getPosition() const {
    return this->position;
}

/**
 * @return {int} Coin value
 */
int Coin::getValue() const {
    return this->value;
}
