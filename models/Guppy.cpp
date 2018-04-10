#include "Guppy.hpp"

const double Guppy::PRODUCE_COIN_PERIOD = 5;
const std::string Guppy::assetPathLeft = "assets/img/guppy_left.png";
const std::string Guppy::assetPathRight = "assets/img/guppy_right.png";

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
    if (this->getPosition()->getAbsis() > this->getDestination()->getAbsis()) {
        return Guppy::assetPathLeft;
    } else {
        return Guppy::assetPathRight;
    }
}