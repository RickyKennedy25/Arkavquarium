#include "Guppy.hpp"

/**
 * Construct Guppy
 * Set produceCoinTimer to 0
 */
Guppy::Guppy() {
    //
}

/**
 * Modulo produceCoinTimer with PRODUCE_COIN_PERIOD
 * @return {bool} PRODUCE_COIN_PERIOD == produceCoinTimer before edited
 */
bool Guppy::isProduceCoin() {
    return true;
}

/**
 * Increment produceCoinTimer
 * If isStarving, move Guppy to nearest food
 * If position is equal destination, random new destination
 * Otherwise move to destination
 */
void Guppy::update() {
    //
}
