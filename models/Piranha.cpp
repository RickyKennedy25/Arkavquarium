#include "Piranha.hpp"

/**
 * Construct Piranha with isJustEatGuppy as False
 */
Piranha::Piranha(int maxWidth, int maxHeight):Fish::Fish(maxWidth, maxHeight){
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