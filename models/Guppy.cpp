#include "Guppy.hpp"

const double Guppy::PRODUCE_COIN_PERIOD = 5;

/**
 * Construct Guppy
 * Set produceCoinTimer to 0
 */
Guppy::Guppy() : Fish::Fish()
{
    this->produceCoinTimer =0;
}

/**
 * Modulo produceCoinTimer with PRODUCE_COIN_PERIOD
 * @return {bool} PRODUCE_COIN_PERIOD == produceCoinTimer before edited
 */
bool Guppy::isProduceCoin() {
    return this->produceCoinTimer==PRODUCE_COIN_PERIOD;
}

/**
 * Increment produceCoinTimer
 */
void Guppy::update() {
    this->produceCoinTimer++;
}
