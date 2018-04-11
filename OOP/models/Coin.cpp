#include <iostream>
#include "Coin.hpp"

const std::string Coin::assetPathCoin = "assets/img/coin_shine.png";
const std::string Coin::assetPathRuby = "assets/img/ruby.png";

/**
 * Construct Coin at random position and random value
 * assume value less than 10
 */
Coin::Coin(int maxWidth, int maxHeight) {
    this->position = new Position(maxWidth,maxHeight,true);
    // this->position->setOrdinate(100);
    this->value = rand() %10; 
}

/**
 * Construct Coin at position
 * @param {int} value of coin
 * @param {Position} initial position
 */
Coin::Coin(int value, Position position) {
    this->position = new Position(position.getAbsis(), position.getOrdinate() );
    this->value = value;
}

/**
 * Decrease y-position by velocity less than maxVelocity
 */
void Coin::move(int maxHeight, double elapsedSeconds) {
    Position *bottom = new Position(0, maxHeight-(maxHeight/10), false);
    this->getPosition()->moveVertical(*bottom, elapsedSeconds * MAX_VELOCITY);
}

/**
 * @return {Position*} Coin position
 */
Position* Coin::getPosition() const {
    return this->position;
}

/**
 * @return {int} Coin value
 */
int Coin::getValue() const {
    return this->value;
}

/**
 * @return {std::string} asset path
 */
std::string Coin::getAssetPath()
{
    if(this->getValue() < 50 ){
        return Coin::assetPathCoin;
    } else {
        return Coin::assetPathRuby;
    }
    
}
