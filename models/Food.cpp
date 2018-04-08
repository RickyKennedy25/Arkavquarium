#include <iostream>
#include "Food.hpp"

/**
 * Construct Food at random position and 0 ordinate
 */
Food::Food() {
    this->position = new Position(800,600,true);
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
 * Move Food to dest
 * @param {Positon} destination
 */
void Food::move(Position* dest) {
    this->position->moveVertical(*dest,(double)MAX_VELOCITY);
}

/**
 * @return {Position*} Food Position 
 **/
Position* Food::getPosition() {
    return this->position;
}