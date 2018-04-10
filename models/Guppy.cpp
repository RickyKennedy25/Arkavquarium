#include "Guppy.hpp"

const double Guppy::PRODUCE_COIN_PERIOD = 5;
const int Guppy::COIN_VALUE_STEP_ONE = 10;
const int Guppy::COIN_VALUE_STEP_TWO = 20;
const int Guppy::COIN_VALUE_STEP_THREE = 40;
const int Guppy::MAX_VELOCITY = 40;
const int Guppy::PRICE = 100;
const std::string Guppy::assetPath = "assets/img/guppy";

/**
 * Construct Guppy
 * Set produceCoinTimer to 0
 * Set growthStep to GROWTH_STEP_ONE
 * Set maxVelocity as guppy max velocity
 */
Guppy::Guppy(int maxWidth, int maxHeight) : Fish::Fish(maxWidth, maxHeight) {
    this->produceCoinTimer = 0;
	this->growthStep = stepOne;
    this->maxVelocity = Guppy::MAX_VELOCITY;
}

/**
 * @return {tGrowthStep} this growthStep
 */
tGrowthStep Guppy::getGrowthStep() const {
    return this->growthStep;
}

/**
 * @return {int} this growthStep in int
 */
int Guppy::getGrowthStepInt() const {
    if (this->growthStep == stepOne) { return 1; }
    else if (this->growthStep == stepTwo) { return 2; }
    else { return 3;}
}

/**
 * @param {tGrowthStep} new growthStep
 */
void Guppy::setGrowthStep(tGrowthStep growthStep) {
    this->growthStep = growthStep;
}

/**
 * Reduce produceCoinTimer with PRODUCE_COIN_PERIOD
 * @return {int} 0 if PRODUCE_COIN_PERIOD == produceCoinTimer before edited
 *               this growthStep value if not
 */
int Guppy::isProduceCoin() {
    if (this->produceCoinTimer < PRODUCE_COIN_PERIOD) {
        return 0;
    } else {
        this->produceCoinTimer -= PRODUCE_COIN_PERIOD;
        if (this->getGrowthStep() == stepOne) { return Guppy::COIN_VALUE_STEP_ONE; }
        else if (this->getGrowthStep() == stepTwo) { return Guppy::COIN_VALUE_STEP_TWO; }
        else { return Guppy::COIN_VALUE_STEP_THREE; }
    }
}

/**
 * Override parent eat(). After parent eat(),
 * if exceed minimum eatCounter, upgrade growthStep to next step
 */
void Guppy::eat() {
    Fish::eat();
	if (this->eatCounter == FIRST_GROWTH_EAT_COUNTER)
		this->growthStep = stepTwo;
	else if(this->eatCounter == SECOND_GROWTH_EAT_COUNTER)
		this->growthStep = stepThree;
}

/**
 * Increment produceCoinTimer by elapsedSeconds
 * @param {double} elapsed seconds since previous loop
 */
void Guppy::update(double elapsedSeconds) {
    this->produceCoinTimer += elapsedSeconds;
}

/**
 * @return {std::string} asset path
 */
std::string Guppy::getAssetPath() {
    std::string path = Guppy::assetPath;

    if (this->getOrientation() == left) { path += "_left"; }
    else { path += "_right"; }

    if (this->getGrowthStep() == stepOne) { path += "_small"; }
    else if (this->getGrowthStep() == stepTwo) { path += "_medium"; }
    else { path += "_big"; }

    if (this->isStarving()) { path += "_hungry"; }

    path += ".png";
    return path;
}

int Guppy::getPrice() {
    return Guppy::PRICE;
}