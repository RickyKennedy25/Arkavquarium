#include <iostream>
#include "Snail.hpp"

const std::string Snail::assetPath = "assets/img/snail";

/**
 * Construct Snail with random position
 */
Snail::Snail(int maxWidth, int maxHeight) {
   this->position = new Position(maxWidth, maxHeight, true);
   this->position->setOrdinate(maxHeight/10);
   this->orientation = left;
}

/**
 * Returns the snail position
 */
Position* Snail::getPosition() const {
    return this->position;
}

/**
 * Move position to dest not exceeding MAX_VELOCITY
 * @param {Position} destination
 */
void Snail::moveToDestination(Position* position, double elapsedSeconds) {
    this->position->moveHorizontal(*position, elapsedSeconds * MAX_VELOCITY);
    if (this->position->getAbsis() < position->getAbsis()) {
        this->orientation = right;
    } else {
        this->orientation = left;
    }
}

/**
 * @return {std::string} asset path
 */
std::string Snail::getAssetPath() {
    std::string path = Snail::assetPath;

    if (this->orientation == left) { path += "_left"; }
    else { path += "_right"; }

    path += ".png";

    return path;
}