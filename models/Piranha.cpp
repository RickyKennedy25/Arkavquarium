#include "Piranha.hpp"

/**
 * Construct Piranha with isJustEatGuppy as False
 */
Piranha::Piranha():Fish::Fish(){
    this->isJustEatGuppy= false;
}

/**
 * Set isJustEatGuppy to false
 * @return {bool} isJustEatGuppy before edited
 */
bool Piranha::isProduceCoin() {
    bool Temp = this->isJustEatGuppy;
    this->isJustEatGuppy = false;
    return Temp;
}

/**
 * Set isJustEatGuppy to True
 */
void Piranha::eatGuppy() {
    this->isJustEatGuppy = true;
}