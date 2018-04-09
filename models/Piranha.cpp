#include "Piranha.hpp"

const std::string Piranha::assetPathLeft = "assets/img/Piranha_left.png";
const std::string Piranha::assetPathRight = "assets/img/Piranha_right.png";
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

/**
 * @return {std::string} asset path
 */
std::string Piranha::getAssetPath() {
    if (this->getPosition()->getAbsis() > this->getDestination()->getAbsis()) {
        return Piranha::assetPathLeft;
    } else {
        return Piranha::assetPathRight;
    }
}