#include "Piranha.hpp"

const std::string Piranha::assetPath = "assets/img/piranha";
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
    std::string path = Piranha::assetPath;
    if (this->getOrientation() == left) {
        path += "_left";
    } else {
        path += "_right";
    }

    if (this->getGrowthStep() == stepOne) {
        path += "_small";
    } else if (this->getGrowthStep() == stepTwo) {
        path += "_medium";
    } else {
        path += "_big";
    }
    path += ".png";
    return path;
}