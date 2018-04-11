#include "Piranha.hpp"

const std::string Piranha::assetPath = "assets/img/piranha";
const int Piranha::PRICE = 1000;
const int Piranha::MAX_VELOCITY = 50;

/**
 * Construct Piranha with isJustEatGuppy as False
 * and maxVelocity as piranha max velocity
 */
Piranha::Piranha(int maxWidth, int maxHeight):Fish::Fish(maxWidth, maxHeight){
    this->isJustEatGuppy = 0;
    this->maxVelocity = Piranha::MAX_VELOCITY;
}

/**
 * Set isJustEatGuppy to 0
 * @return {int} isJustEatGuppy
 */
int Piranha::isProduceCoin() {
    int Temp = this->isJustEatGuppy;
    this->isJustEatGuppy = 0;
    return Temp;
}

/**
 * Override parent eat(). After parent eat(),
 * Set isJustEatGuppy to True
 * @param {int} growth step of fish eaten
 */
void Piranha::eat(int x) {
    Fish::eat();
    this->isJustEatGuppy = x+1;
}

/**
 * @return {std::string} asset path
 */
std::string Piranha::getAssetPath() {
    std::string path = Piranha::assetPath;

    if (this->getOrientation() == left) { path += "_left_big"; }
    else { path += "_right_big"; }

    if (this->isStarving()) { path += "_hungry"; }

    path += ".png";
    return path;
}

int Piranha::getPrice() {
    return Piranha::PRICE;
}
