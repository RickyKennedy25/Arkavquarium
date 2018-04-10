#include "Guppy.hpp"

const double Guppy::PRODUCE_COIN_PERIOD = 5;
const std::string Guppy::assetPath = "assets/img/guppy";

/**
 * Construct Guppy
 * Set produceCoinTimer to 0
 */
Guppy::Guppy(int maxWidth, int maxHeight) : Fish::Fish(maxWidth, maxHeight) {
    this->produceCoinTimer = 0;
}

/**
 * Modulo produceCoinTimer with PRODUCE_COIN_PERIOD
 * @return {bool} PRODUCE_COIN_PERIOD == produceCoinTimer before edited
 */
bool Guppy::isProduceCoin() {
    return this->produceCoinTimer == PRODUCE_COIN_PERIOD;
}

/**
 * Increment produceCoinTimer
 */
void Guppy::update() {
    this->produceCoinTimer++;
}

/**
 * @return {std::string} asset path
 */
std::string Guppy::getAssetPath() {
    std::string path = Guppy::assetPath;
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